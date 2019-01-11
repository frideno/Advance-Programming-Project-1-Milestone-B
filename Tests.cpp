
#include <functional>
#include "Tests.h"
#include "Utils.h"

template<class T>
void Tests::testSearcher(Searcher <T> &searcher, Searchable <T> &searchable) {

    T sol = searcher.search(searchable);

    int n = searcher.getNumberOfNodesEvaluated();
}

WeightedGraph *Tests::buildGraphFromString(vector<string> lines) {

    vector<vector<int>> m;
    int i = 0;

    for(string& line: lines) {

        vector<string> IthAdjs = Utils::strSplit(line, ' ');
        vector<int> v;
        for(int j = 0; j < IthAdjs.size(); j++) {
            v.push_back(Utils::to_number(IthAdjs[j]));
        }
        m.push_back(v);

        i++;
    }

    return new WeightedGraph(i, m);

}

CubeSearch *Tests::buildRandomCubeGraph(int N) {


    vector<vector<double>> v ;

    for (int i = 0; i < N; i++) {

        vector<double> vi;
        for (int j = 0; j < N; j++) {

            // addes a weight between 0 and 999.
            vi.push_back(rand() % 1000);
        }

        v.push_back(vi);
    }

    return new CubeSearch (N, ref(v));
}
