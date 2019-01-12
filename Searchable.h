//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHABLE_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>
    using std::vector;

/*
 * Searchable is an interace representing a search problem.
 * */
    template<class T>
    class Searchable {
    public:
        virtual State<T>* getInitialState() const = 0;

        virtual State<T>* getGoalState() const = 0;

        virtual vector<State<T>*> getAllPossibleStates(State<T> s) = 0;


    };
#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHABLE_H
