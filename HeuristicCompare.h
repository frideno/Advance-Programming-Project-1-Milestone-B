//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICCOMPARE_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICCOMPARE_H

#include <unordered_map>
#include "Heuristic.h"

template <class T>
class HeuristicCompare {

    Heuristic<T> heuristic;


public:

    bool operator()(const SearcherState<T> &s1, const SearcherState<T> &s2) const {

        return s1.getDistance() + s1.getTotalCost() > s2.getDistance() + s2.getTotalCost();
    }

};


#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_HEURISTICCOMPARE_H
