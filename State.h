//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#define ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#include <vector>

/*
 * State<T> interface represents a verctice in graph, which has a cost, a T representor and possibly a camefrom
 * other state in a path.
 *
 * */
template<class T>
class State {


public:


    // get the state representor T.

    virtual T getState() const = 0;

    // get the cost of visiting the state.

    virtual double getCost() const = 0;

    // get the state pointer that we came from to this state in a path.

    virtual State<T>* getCameFrom() const = 0;

    // sets the state pointer that we came from to this state in a path.
    virtual void setCameFrom(State<T>* cameFrom) = 0;

    virtual bool operator==(const State<T>& other) = 0;
};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H
