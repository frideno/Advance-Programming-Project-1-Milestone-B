//
// Created by omri on 1/10/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_WEIGHTEDGRAPH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_WEIGHTEDGRAPH_H


#include <string>
#include <vector>
#include "exceptions.h"
#include "Searchable.h"

class WeightedGraph {

private:

    int _n;
    std::vector<std::vector<int>> _matrix;

public:

    // initilize NxN graph with no edges.
    WeightedGraph (int N);

    // initilize NxN graph with edges of the given weights.
    WeightedGraph (int N, std::vector<std::vector<int>> adjMatrixWeights);

    // translate the graph to string.
    std::string toString();

    inline std::vector<std::vector<int>> getAdjMatrix() const {return _matrix;};

    inline int getSize() const {return _n;};


};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_WEIGHTEDGRAPH_H
