//
// Created by omri on 1/9/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_GRAPH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_GRAPH_H


#include <string>
#include <map>
#include "Searchable.h"

template  <class T>
class Graph {

private:

    vector<State<T>> _vertices;

    map <State<T>*, vector<State<T>*>> _adjsList;

public:

    Graph(vector<State<T>> vertices,

    vector<State<T>*> getNeighbors(State<T>* s);


};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_GRAPH_H
