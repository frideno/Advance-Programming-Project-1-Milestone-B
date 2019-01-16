//
// Created by galpolitzer6 on 1/16/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTICMANHATAN_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTICMANHATAN_H

#include "Heuristic.h"
#include <map>

template <class T>
class HeuristicManhatan : public Heuristic<T> {

    std::map<SearcherState<T>&, double > _distances;

    double computeH(const SearcherState<T> &s1, const SearcherState<T> &s2) override {
        return 0;
    }

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_HEURISTICMANHATAN_H
