//
// Created by omri on 1/11/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_CUBESEARCH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_CUBESEARCH_H

#include <utility>
#include "Searchable.h"
#include <map>

using std::pair;
using std::map;

class CubeSearch : public Searchable<pair<int, int>> {
private:

    int _N;
    vector<vector< State<pair<int,int>>* >> _states;

public:

    CubeSearch(int N);

    CubeSearch(int N, vector<vector<double>> weights);

    // translate the graph to string.
    std::string toString();

    State<pair<int, int>> getInitialState() const override;

    State<pair<int, int>> getGoalState() const override;

    vector<State<pair<int, int>>> getAllPossibleStates(State<pair<int, int>> s) override;
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_CUBESEARCH_H
