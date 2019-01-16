//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_COMPARATOR_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_COMPARATOR_H

#include "SearcherState.h"

template <class T>
class SimpleCompare {

public:

    bool operator()(const SearcherState<T> &s1, const SearcherState<T> &s2) const {

       return s1.getTotalCost() > s2.getTotalCost();

    }
};

#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_COMPARATOR_H
