//
// Created by omri on 1/12/19.
//

#include "CompareAlgorithms.h"
#include "Utils.h"
#include <fstream>


CompareAlgorithms::CompareAlgorithms(vector<Searcher<pair<int, int>> *> &algorithms, string g, string s) :
        _algorithms(algorithms), _graphs(g), _solutions(s) {
    for(int i = 0; i < algorithms.size(); i++)
        _preformences.push_back(0);
}

void CompareAlgorithms::compare(int numberOfMatrices, pair<int, int> &sizesRange) {

    int minSize = sizesRange.first, maxSize = sizesRange.second;
    CubeSearch* g;

    std::ofstream graphsFile(_graphs), solutionsFile(_solutions);

    /*
     * for the chart making: size - number of nodes evaluated.
     * */
    vector<std::ofstream> forTheChart;
    int numberOfAlgorithms = _algorithms.size();
    for (int i = 0; i < numberOfAlgorithms; i++) {

        // opens a file 'chart i.txt'.
        forTheChart.push_back(std::ofstream("../chart" + to_string(i) + ".txt"));
    }


    graphsFile << to_string(numberOfMatrices) << endl;

    int jump = (maxSize - minSize) / numberOfMatrices;
    for (int i = 0; i < numberOfMatrices; i++) {

        // run the algorithms on a random matrix.

        int size = minSize + i * jump;
        g = buildRandomCubeGraph(size, 0.05);

        // record the graph in the file.
        graphsFile << to_string(size) << endl;
        graphsFile << g->toString() << endl;

        for (int j = 0; j < _algorithms.size(); j++) {

            Path<pair<int, int>>* path = _algorithms[j]->search(*g);

            // record the solution in the file.
            solutionsFile << to_string(_algorithms[j]->getNumberOfNodesEvaluated()) <<
                ',' << Utils::to_string(path->getCost()) << endl;

            forTheChart[j] << to_string(size) << ' ' << to_string(_algorithms[j]->getNumberOfNodesEvaluated()) << endl;
            delete path;
        }

        delete g;


    }

}


CompareAlgorithms::~CompareAlgorithms() {

}

CubeSearch *CompareAlgorithms::buildRandomCubeGraph(int N, double p) {


    vector<vector<double>> v ;

    for (int i = 0; i < N; i++) {

        vector<double> vi;
        for (int j = 0; j < N; j++) {

            // addes a random weight between 0 and 999.

            int rnd = rand() % 1000;

            // for a problability p, set the weight to be -1 (infinity).
            if (p != 0 && rand() % (int) (1/p) == 0)
                rnd = -1;

            vi.push_back(rnd);
        }

        v.push_back(vi);
    }

    return new CubeSearch (N, N, v);
}