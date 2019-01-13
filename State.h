//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#define ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#include <vector>
#include <cmath>


#define INF_VALUE -1

template<class T>
class State {
private:

    T _stateRep;

    double _cost;   // the cost of a path from start to this state.

    State<T> *_cameFrom;

public:


    State(T state, double cost) :
            _stateRep(state), _cost(cost) {
        if (cost == INF_VALUE)
            _cost = INFINITY;
    }


    inline T getState() const {
        return _stateRep;
    }

    inline double getCost() const {
        return _cost;
    }

    inline State<T> *getCameFrom() const {
        return _cameFrom;
    }

    void setCameFrom(State<T> *cameFrom) {
        _cameFrom = cameFrom;
    }

    bool operator==(const State<T>& other) {return _stateRep == other.getState();};
};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H
