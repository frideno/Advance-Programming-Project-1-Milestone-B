//
// Created by galpolitzer6 on 1/16/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSTATE_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSTATE_H

#include "State.h"

template<class T>
class SearcherState {
private:

    State<T> *_wrapped;

    double _totalCost;

    double _distance;

public:

    SearcherState() : _wrapped(nullptr), _totalCost(0) {}

    SearcherState(State<T>* wrapped, double totalCost, double distance) :
            _wrapped(wrapped), _totalCost(totalCost), _distance(distance) {
    }

    SearcherState(State<T>* wrapped, double totalCost) :
            _wrapped(wrapped), _totalCost(totalCost) {

    }

    inline State<T>* getWrappedState() const {
        return _wrapped;
    }

    inline double getTotalCost() const {
        return _totalCost;
    }

    inline void setTotalCost(double totalCost) {
        _totalCost = totalCost;
    }

    inline double getDistance() {
        return _distance;
    }

    bool operator==(const SearcherState<T> &other) const { return _wrapped == other.getWrappedState(); }

    bool operator!=(const SearcherState<T> &other) const { return !(*this == other); }

    ~SearcherState() {}
};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSTATE_H
