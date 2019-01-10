//
// Created by omri on 1/9/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_BESTFIRSTSEARCH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_BESTFIRSTSEARCH_H


#include "Searcher.h"

template <class Solution>
class BestFirstSearch: Searcher<Solution> {

:
    Solution search(Searchable<Solution> &searchable) override;

    int getNumberOfNodesEvaluated() const override;

    //
    vector<State<Solution>*> backTrace(State<Solution> *s);

};
#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_BESTFIRSTSEARCH_H
