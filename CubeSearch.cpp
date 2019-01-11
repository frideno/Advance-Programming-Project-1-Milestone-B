//
// Created by omri on 1/11/19.
//

#include "CubeSearch.h"
#include "exceptions.h"

CubeSearch::CubeSearch(int N):
    _N(N) {

    for (int i = 0; i < N; i++) {

        vector< State<pair<int, int>>* > row;
        for (int j = 0; j < N; j++) {

            pair<int, int> p(i, j);
            State<pair<int,int>>* s = new State<pair<int,int>>(p);
            s->setCost(0);
            row.push_back(s);
        }
        _states.push_back(row);
    }
}

CubeSearch::CubeSearch(int N, vector<vector<double>> weights):
    _N(N) {

    // checks for exception in size.

    if(weights.size() != N)
        throw exceptionsLibrary::BasicException("size N not comfortable for weights size");

    for (int i = 0; i < N; i++) {

        vector< State<pair<int, int>>* > row;

        // checks for exception in size.

        if(weights[i].size() != N)
            throw exceptionsLibrary::BasicException("size N not comfortable for weights size");

        for (int j = 0; j < N; j++) {

            pair<int, int> p(i, j);
            State<pair<int,int>>* s = new State<pair<int,int>>(p);
            s->setCost(weights[i][j]);
            row.push_back(s);
        }
        _states.push_back(row);
    }
}

std::string CubeSearch::toString() {
    
    std::string s;
    for (int i = 0; i < _states.size(); i++) {
        if (_states[i].size() <= 0)
            continue;

        int n = _states[i].size() - 1;
        for (int j = 0; j < n; j++) {
            s += std::to_string(_states[i][j]->getCost());
            s += " ";
        }
        s += std::to_string(_states[i][n]->getCost());
        s += '\n';

    }
    return  s;
}

State<pair<int, int>> CubeSearch::getInitialState() const {
   return *_states[0][0];
}

State<pair<int, int>> CubeSearch::getGoalState() const {
    return *_states[_N-1][_N-1];
}

vector<State<pair<int, int>>> CubeSearch::getAllPossibleStates(State<pair<int, int>> s) {

    vector<State<pair<int, int>>> neighbors;

    // add the up, down, left, right to the neighbors.

    pair<int,int> pos = s.getState(), neighbor;
    int i = pos.first, j = pos.second;

    // check for if s is in the most up row
    if (i != 0) {

        // adds the up neighbor.
        neighbors.push_back(*_states[i-1][j]);
    }

    // check for if s in the most down row
    if (i != _N -1) {

        // adds the down neighbor.
        neighbors.push_back(*_states[i+1][j]);
    }

    // check for if s in the most right column
    if (j != _N - 1) {

        // adds the right neighbor.
        neighbors.push_back(*_states[i][j+1]);
    }

    // check for if s in the most left column
    if (j != 0) {

        // adds the left neighbor.
        neighbors.push_back(*_states[i][j-1]);
    }

    return neighbors;

}
