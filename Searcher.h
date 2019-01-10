//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHER_H

#include "Searchable.h"

template <class Solution>
class Searcher{

    // the search algorithm.
    virtual Solution search(Searchable<Solution>& searchable) = 0;

    // the number of nodes that evaluated in the search.
    virtual int getNumberOfNodesEvaluated() const = 0;

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHER_H
