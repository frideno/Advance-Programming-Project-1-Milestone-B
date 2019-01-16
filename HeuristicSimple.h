//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICSIMPLE_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICSIMPLE_H

#include "Heuristic.h"

template <class T>
class HeuristicSimple : public Heuristic<T> {
public:

    HeuristicSimple() {}

    virtual ~HeuristicSimple() {}

private:
    double computeH(const SearcherState<T>& s) const override {
        return s.getTotalCost();
    }
};

#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICSIMPLE_H
