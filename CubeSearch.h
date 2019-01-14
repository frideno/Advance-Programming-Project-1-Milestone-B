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
using std::string;

class CubeSearch : public Searchable<pair<int, int>> {
private:

    // the cube is N lines, and M columns.
    int _N, _M;

    vector<vector< State<pair<int,int>>* >> _states;

    pair<int, int> _s, _t;  // source and target points.


    void initStates(vector<vector<double>>& weights);

public:


    CubeSearch(int N, int M, vector<vector<double>> weights);

    CubeSearch(int N, int M, vector<vector<double>> weights, pair<int, int> start, pair<int, int> end);

    // translate the graph to string.
    std::string toString();

    State<pair<int, int>>* getInitialState() const override;

    State<pair<int, int>>* getGoalState() const override;

    vector<State<pair<int, int>>*> getAllPossibleStates(State<pair<int, int>>* s) override;

    virtual ~CubeSearch();
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_CUBESEARCH_H
