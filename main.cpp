
#include <iostream>

#include "Tests.h"
#include "FileCacheManager.h"
#include "CompareAlgorithms.h"
#include "BestFirstSearch.h"
#include "BFS.h"


int main() {


//    VisualGraph scale(5);
//    for (int n = 10; n < 50; n++) {
//

//        CubeSearch *cs = Tests::buildRandomCubeGraph(n);
//
//        // make a map of algos
//        // loop over them with:
//
//        vector<int> times;
//        for (int i = 0; i < algorithms.size(); i++) {
//
//            Tests::MySearcher(*algorithms[i], *cs);
//
//            // records the time (number of nodes evaluated).
//            scale.addPoint(i, algorithms[i]->getNumberOfNodesEvaluated());
//        }
//
//
//    }



    using std::cin;
    using std::vector;
    using std::endl;

    vector<Searcher<pair<int, int>>*> algorithms = {
            //new BestFirstSearch(),
           // new DFS(),
           // new BestFirstSearch<pair<int, int>>() // ,
          new BFS<pair<int, int>>()
          //  new AStar()
    };

    CompareAlgorithms comparator(algorithms, "../graphs.txt", "../solution.txt");
    pair<int, int> sizeRange = make_pair(10,50);
    comparator.compare(10, sizeRange);

    for (int i = 0; i < algorithms.size(); i++) {
        delete algorithms[i];
    }

//    ClientHandler* clientHandler = new SearchProblemClientHandler();
//    clientHandler->handleClient(0,0);
//    delete clientHandler;

//    FileCacheManager c("../cache.txt");
//    vector<vector<double>> v = {
//            {1,2,3, 1},
//            {1,1,1, 1},
//            {0,9, INFINITY, 0}
//    };
//    CubeSearch cs (3, 4, v);
//
//
//    State<pair<int, int>> i = cs.getInitialState();
//    vector<State<pair<int,int>>> q = cs.getAllPossibleStates(i);
//
//    for (int k = 0; k < q.size(); k ++)
//        cout << q[k].getState().first << ',' << q[k].getState().second << ':' << q[k].getCost() << endl;
//
//    cout << endl;
//
//    q = cs.getAllPossibleStates(q[0]);
//    for (int k = 0; k < q.size(); k ++)
//        cout << q[k].getState().first << ',' << q[k].getState().second << ':' << q[k].getCost() << endl;
//
//    cout << endl;
//    q = cs.getAllPossibleStates(q[2]);
//    for (int k = 0; k < q.size(); k ++)
//        cout << q[k].getState().first << ',' << q[k].getState().second << ':' << q[k].getCost() << endl;
//
//    cout << endl;
//    q = cs.getAllPossibleStates(q[1]);
//    for (int k = 0; k < q.size(); k ++)
//        cout << q[k].getState().first << ',' << q[k].getState().second << ':' << q[k].getCost() << endl;
//
//    string s = cs.toString();
//    if (!c.hasSolution(s)) {
//        c.saveSolution(s, "UP,DOWN,RIGHT,LEFT");
//        cout << "new" << endl;
//    }
//    else {
//        cout << "exsists" << endl;
//    }
}