
#include "WeightedGraph.h"
#include "Tests.h"

int main() {


    for (int n = 10; n < 5000) {

        CubeSearch *cs = Tests::buildRandomCubeGraph(n);

        // make a map of algos
        // loop over them with:
        Tests::testSearcher(cs, algos[i]);

        // store algo->number of vertices.

        // compare best.

    }



    // file cache manager test:
//
//    FileCacheManager c("../cache.txt");
//    vector<vector<double>> v = {
//            {1,2,3},
//            {1,1,1},
//            {0,9, INFINITY}
//    };
//    CubeSearch cs (3, v);
//
//
//    cout << cs.toString() << endl;
//    cout << endl;
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

    //cout << q[1].getState();
}