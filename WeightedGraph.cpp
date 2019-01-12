//

#include "WeightedGraph.h"
#include "Utils.h"
#include <algorithm>
#include <iostream>

WeightedGraph::WeightedGraph(int N) {

    // handling illegal matrix.
    if (N <= 0)
        throw exceptionsLibrary::BasicException("weighted graph initialized with illigal size.");

    _n = N;
    _matrix.reserve(N);

    // intilizing rows of matrix.
    int i;
    for (i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++)
            v.push_back(0);
        _matrix.push_back(v);
    }
}



WeightedGraph::WeightedGraph(int N, std::vector<std::vector<int>> adjMatrixWeights):
    WeightedGraph(N) {

    // if the matrix given is not in size N, thrwo exception.
    if (adjMatrixWeights.size() != N)
        throw exceptionsLibrary::BasicException("weighted graph initialized with illigal size.");


   // intilizing the graph with the weights.
   for(int i = 0; i < N; i++) {

       for (int j = 0; j < N; j++) {

           _matrix[i][j] = adjMatrixWeights[i][j];
       }
   }

}

std::string WeightedGraph::toString() {
    std::string s;
    for (int i = 0; i < _matrix.size(); i++) {
        if (_matrix[i].size() <= 0)
            continue;

        int n = _matrix[i].size() - 1;
        for (int j = 0; j < n; j++) {
            s += Utils::to_string(_matrix[i][j]);
            s += " ";
        }
        s += Utils::to_string(_matrix[i][n]);
        s += '\n';

    }
    return  s;
}
// Created by omri on 1/10/19.
//

