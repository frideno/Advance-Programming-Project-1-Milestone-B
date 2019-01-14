//
// Created by omri on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_COMPAREALGORITHMS_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_COMPAREALGORITHMS_H

#include <utility>
#include <string>
#include <iostream>
#include "Searcher.h"
#include "CubeSearch.h"

using std::pair;
using std::string;
using std::to_string;
using std::endl;

class CompareAlgorithms {

private:

    // algorithms searcher table.
    vector<Searcher<pair<int, int>>*> _algorithms;

    // preformences table.
    vector<int> _preformences;

    // record file names.
    string _graphs, _solutions;

    // builds and return a random graph of NxN size, with probability p of a cell to be INFITY value.
    CubeSearch* buildRandomCubeGraph(int N, double p);

public:

    // constructor.
    CompareAlgorithms(vector<Searcher<pair<int,int>>*>& algorithms, string graphsFileName, string solutionsFileName);

    // compare the algorithms with numberOfMatrices different matrices, that are
    // in the range of size sizesRange, and store the preformences in the table.

    void compare(int numberOfMatrices, pair<int, int>& sizesRange);


    ~CompareAlgorithms();

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_COMPAREALGORITHMS_H
