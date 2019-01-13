
#include <iostream>
#include <thread>

#include "Tests.h"
#include "FileCacheManager.h"
#include "CompareAlgorithms.h"
#include "BestFirstSearch.h"
#include "TestSearcher.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "Utils.h"


int main(int argc, char *argv[]) {



    using std::cin;
    using std::cout;
    using std::cerr;

    using std::vector;
    using std::endl;

    int portNumber = 12345;
    if (argc > 1) {
        portNumber = Utils::to_number(argv[1]);
    } else {
        cerr << "bad port inserted in args" << endl;
        exit(1);
    }


    vector<Searcher<pair<int, int>>*> algorithms = {
            //new BestFirstSearch(),
           // new DFS(),
           // new BestFirstSearch<pair<int, int>>() // ,
          new TestSearcher<pair<int, int>>()
          //  new AStar()
    };

    server_side::Server* s = new MySerialServer(2);

    CacheManager* ca = new FileCacheManager("../cache.txt");
    Searcher<pair<int, int>> *se = new TestSearcher<pair<int,int>>();  // the best of the runners.

    ClientHandler * c = new MyClientHandler(ca, se);
    s->open(portNumber, *c);


//    CompareAlgorithms comparator(algorithms, "../graphs.txt", "../solution.txt");
//    pair<int, int> sizeRange = make_pair(10,50);
//    comparator.compare(10, sizeRange);


    for (int i = 0; i < algorithms.size(); i++) {
        delete algorithms[i];
    }
    delete c;
    delete s;
}