//
// Created by omri on 1/15/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_NORMALSTATE_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_NORMALSTATE_H

#include <cmath>
#include "State.h"

#define INF_VALUE -1

template<class T>
class NormalState: public State<T> {
private:

    T _stateRep;

    double _cost;   // the cost of a path from start to this state.

    State<T> *_cameFrom;

public:


    NormalState(T state, double cost) :
            _stateRep(state), _cost(cost), _cameFrom(nullptr) {
        if (cost == INF_VALUE)
            _cost = INFINITY;
    }


    inline T getState() const {
        return _stateRep;
    }

    inline double getCost() const {
        return _cost;
    }

    inline State<T>* getCameFrom() const {
        return _cameFrom;
    }

    void setCameFrom(State<T> *cameFrom) {
        _cameFrom = cameFrom;
    }

    bool operator==(const State<T>& other) {return _stateRep == other.getState();};

    ~NormalState() {}
};
#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_NORMALSTATE_H
