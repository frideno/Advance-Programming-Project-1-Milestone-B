
#include <iostream>
#include <thread>

#include "Tests.h"
#include "FileCacheManager.h"
#include "CompareAlgorithms.h"
#include "TestSearcher.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "MyClientHandler.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "A_Star.h"

void compareAlgosForFile(vector<Searcher<pair<int,int>> *>& algorithms);


int main(int argc, char *argv[]) {

////DFS.h Heuristic.h HeuristicCompare.h HeuristicManhatan.h A_Star.h A_Star.cpp AbstractSearcher.cpp AbstractSearcher.h BestFirstSearch.h BestFirstSearch.cpp
    using std::cin;
    using std::cout;
    using std::cerr;

    using std::vector;
    using std::endl;

    int portNumber = 12346;
//    if (argc > 1) {
//        portNumber = Utils::to_number(argv[1]);
//    } else {
//        cerr << "bad port inserted in args" << endl;
//        exit(1);
//    }


    vector<Searcher<pair<int, int>> *> algorithms = {
            //new BestFirstSearch(),
            new BestFirstSearch<pair<int, int>>(),
            new DFS<pair<int,int>>(),
            new BFS<pair<int,int>>(),
            new A_Star<pair<int,int>>()

            //  new AStar()
    };

    compareAlgosForFile(algorithms);

    server_side::Server *s = new MyParallelServer(2);
    CacheManager *ca = new FileCacheManager("../cache.txt");
    Searcher<pair<int, int>> *se = algorithms[3];  // the best of the runners.

    ClientHandler *c = new MyClientHandler(ca, se);
    try {

        s->open(portNumber, *c);


    } catch (...) {
        for (int i = 0; i < algorithms.size(); i++) {
            delete algorithms[i];
        }
        delete ca;
        delete c;
        delete s;

        // exit with 1.
        return 1;
    }

    for (int i = 0; i < algorithms.size(); i++) {
        delete algorithms[i];
    }
    delete ca;
    delete c;
    delete s;
}
void compareAlgosForFile(vector<Searcher<pair<int,int>> *>& algorithms) {

    CompareAlgorithms comparator(algorithms, "../graphs.txt", "../solution.txt");
    pair<int, int> sizeRange = make_pair(10, 50);
    comparator.compare(10, sizeRange);
}