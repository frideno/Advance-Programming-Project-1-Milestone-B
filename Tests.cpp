
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

