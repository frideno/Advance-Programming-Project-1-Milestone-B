//
// Created by galpolitzer6 on 1/16/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTIC_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTIC_H

#include "SearcherState.h"

template <class T>
class Heuristic {

    virtual double computeH(const SearcherState<T> &s1, const SearcherState<T> &s2) = 0;

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTIC_H
