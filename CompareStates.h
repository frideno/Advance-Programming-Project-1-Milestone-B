//
// Created by omri on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_COSTCOMPARE_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_COSTCOMPARE_H

#include "Compare.h"

template <class T>
class CompareStates : public Compare<T> {
public:
    virtual bool operator() (const State<T> &s1, const State<T> &s2)  const  {
        return s1.getCost() < s2.getCost();
    }

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_COSTCOMPARE_H
