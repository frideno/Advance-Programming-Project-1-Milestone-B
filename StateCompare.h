//
// Created by galpolitzer6 on 1/15/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_STATECOMPARE_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_STATECOMPARE_H

#include "State.h"

template <class T>
class StateCompare {

public:

    bool operator()(const State<T>* s1, const State<T>* s2) {
        return s1->getState() < s2->getState();
    }

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_STATECOMPARE_H
