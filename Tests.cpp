
#include "Tests.h"
#include "Utils.h"

template<class T>
void Tests::testSearcher(Searcher <T> &searcher, Searchable <T> &searchable) {

    T sol = searcher.search(searchable);

    int n = searcher.getNumberOfNodesEvaluated();
}

template<class T>
Graph<string> *Tests::buildGraphFromString(vector<string> lines) {

    vector<State<string>> states;

    for(string& line: lines) {

        vector<string> IthAdjs = Utils::strSplit(line, ',');
    }
}
