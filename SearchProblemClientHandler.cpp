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
        //solution = solver->solve(cube)
        solution = "UP RIGHT DOWN DOWN DOWN";
        cacheManager->saveSolution(problem, solution);
    }

    // write the solution to the server.
    const char* outBuffer = solution.c_str();
    rc = send(socket, outBuffer, solution.length() + 1, 0);


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
}

SearchProblemClientHandler::SearchProblemClientHandler() {
    cacheManager = new FileCacheManager("../cache.txt");
}
