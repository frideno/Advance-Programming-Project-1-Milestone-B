//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#define ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H

#include <vector>
#include <cmath>

template<class T>
class State {
private:

    T _stateRep;

    double _cost;   // the cost of a path from start to this state.

    State<T> *_cameFrom;

public:

    State(T state) :
            _stateRep(state), _cost(INFINITY) {}

    inline T getState() const {
        return _stateRep;
    }

    inline double getCost() const {
        return _cost;
    }

    inline State<T> *getCameFrom() const {
        return _cameFrom;
    }

    void setCost(double _cost) {
        State::_cost = _cost;
    }

    void setCameFrom(State<T> *_cameFrom) {
        State::_cameFrom = _cameFrom;
    }

    bool equals(State<T>& other) {return _stateRep == other.get_stateRep();};
};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_STATE_H
