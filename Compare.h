//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_COMPARATOR_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_COMPARATOR_H

#include "State.h"

template <class T>
class Compare : public std::binary_function<State<T>, State<T>, bool>{

public:

    virtual bool operator() (const State<T> &s1, const State<T> &s2)  const = 0;

};



#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_COMPARATOR_H
