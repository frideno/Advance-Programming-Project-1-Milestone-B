//
// Created by omri on 1/10/19.
//

#include <iostream>
#include <algorithm>
#include <sys/socket.h>
#include "SearchProblemClientHandler.h"
#include "exceptions.h"
#include "FileCacheManager.h"
#include "Utils.h"

#define SPACE ','

void SearchProblemClientHandler::handleClient(int socket) {

    string problem, solution = "solution does not exsists!";

    // reads the problem from the server.

    string line;
    char inBuffer[2048];
    int rc;

    // reading lines from the socket as long as it is not "end".
    while (line != "end") {

        rc = recv(socket, inBuffer, sizeof(inBuffer), 0);

        if (rc < 0) {
            throw exceptionsLibrary::ClientHandlerException("failed recv data");
        }

        line = string(inBuffer);

        // ignore spaces.
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        problem += line;

    }

    // removes last \n.
    problem = problem.substr(0, problem.length() - 1);

    // check if there is a solution to this problem in the cache manager.

    if (cacheManager->hasSolution(problem)) {

        // if there is, pop it.
        solution = cacheManager->getSolution(problem);
    }

    // if there is not, solves it and save the solution.
    else {

        CubeSearch* graph = buildGraph(problem);

        Path<pair<int, int>>* p = _searcher->search(*graph);
        solution = pathToDirections(p);

        cacheManager->saveSolution(problem, solution);
    }

    // write the solution to the server.
    const char* outBuffer = solution.c_str();
    rc = send(socket, outBuffer, solution.length() + 1, 0);


}

string SearchProblemClientHandler::pathToDirections(Path<pair<int, int>> *path) {
    vector<pair<int, int>> p = path->getPath();
    string directions = "{";

    // translate the cordinates to up,down,right,left directions.
    for (int i = 0; i < p.size() - 1; i++) {

        int thisX = p[i].first, thisY = p[i].second, nextX = p[i + 1].first, nextY = p[i + 1].second;

        if (thisX < nextX)
            directions += "RIGHT, ";
        else if (thisX > nextX)
            directions += "LEFT, ";
        else {
            if (thisY < nextY)
                directions += "UP, ";
            else
                directions += "DOWN, ";
        }
    }

    // removes the last ", ".
    directions = directions.substr(0, directions.length() - 2);
    directions += "{";

    return directions;
}

CubeSearch* SearchProblemClientHandler::buildGraph(string& str) {

    // split s to lines.
    vector<string> strLines = Utils::strSplit(str, '\n');

    try {

        //take last two lines to be the start and end points.

        string tLine = strLines[strLines.size() - 1], sLine = strLines[strLines.size() - 2];

        // split x,y by comma for s and t.
        vector<string> tLineSplitted = Utils::strSplit(tLine, ','), sLineSplitted = Utils::strSplit(sLine, ',');

        // translate the string numbers to ints.
        pair<int, int> s = make_pair(Utils::to_number(tLineSplitted[0]),  Utils::to_number(tLineSplitted[1])),
                t = make_pair(Utils::to_number(tLineSplitted[0]),  Utils::to_number(tLineSplitted[1]));


        // make other lines to matrix.
        vector<vector<double>> matrix;
        for (int i = 0; i < strLines.size() - 2; i ++) {

            vector<string> values = Utils::strSplit(strLines[i], SPACE);
            vector<double> intValues;
            for (int j = 0; j < values.size(); j++) {

                intValues.push_back(Utils::to_number(values[j]));
            }
            matrix.push_back(intValues);
        }

        // extracting N and M from the matrix.
        int N = matrix.size(), M = matrix[0].size();

        return new CubeSearch(N, M, matrix, s, t);

    } catch (...) {
        throw exceptionsLibrary::BasicException("failed making a graph from the given output.");
    }


}

SearchProblemClientHandler::~SearchProblemClientHandler() {
    delete cacheManager;
    delete _searcher;
}

SearchProblemClientHandler::SearchProblemClientHandler() {
    cacheManager = new FileCacheManager("../cache.txt");
    _searcher;  // the best of the runners.
}
