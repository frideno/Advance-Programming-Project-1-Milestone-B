#include "Graph.h"

template<class T>
vector<State<T> *> Graph<T>::getNeighbors(State<T> *s) {
    return _adjsList[s];
}

