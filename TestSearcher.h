//
// Created by omri on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H

#include "AbstractSearcher.h"

template <class Solution>
class MySearcher :public AbstractSearcher<Solution> {

public:

    MySearcher() : AbstractSearcher<Solution>() {};
    MySearcher(const Compare<Solution> &comparator) : AbstractSearcher<Solution>(comparator) {};

    Path<Solution>* search(Searchable<Solution>& searchable) {
        State<Solution>& s = searchable.getInitialState();
        while (s != searchable.getGoalState()) {
            vector<State<Solution>> aps = searchable.getAllPossibleStates(s);
            this->_evaluated++;
            s.setCameFrom(&aps[0]);
            s = aps[0];

        }
        return this->backTrace(&searchable.getGoalState());
    }

    virtual ~MySearcher() {}
};
#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
