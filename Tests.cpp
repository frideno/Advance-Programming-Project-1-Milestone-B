
#include "Tests.h"

template<class T>
void Tests::MySearcher(Searcher <T> &searcher, Searchable <T> &searchable) {

    T sol = searcher.search(searchable);

    int n = searcher.getNumberOfNodesEvaluated();
}

