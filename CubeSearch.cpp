//
// Created by omri on 1/11/19.
//

#include <functional>
#include "CubeSearch.h"
#include "exceptions.h"
#include "Utils.h"

#define SPACE ' '

CubeSearch::CubeSearch(int N, int M, vector<vector<double>> weights):
    CubeSearch(N, M, weights, std::make_pair(0,0), std::make_pair(N-1, M-1)) {}


CubeSearch::CubeSearch(int N, int M, vector<vector<double>> weights, pair<int, int> start, pair<int, int> end):
    _N(N), _M(M), _s(start), _t(end) {
// checks for exception in size.

   initStates(weights);
}



void CubeSearch::initStates(vector<vector<double>> &weights) {

    if(weights.size() != _N)
        throw exceptionsLibrary::BasicException("size N not comfortable for weights size");

    for (int i = 0; i < _N; i++) {

        vector< State<pair<int, int>>* > row;

        // checks for exception in size.

        if(weights[i].size() != _M)
            throw exceptionsLibrary::BasicException("size N not comfortable for weights size");

        for (int j = 0; j < _M; j++) {

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
    s += Utils::to_string(_s.first); s += ','; s+= Utils::to_string(_s.second); s+= '\n';
    s += Utils::to_string(_t.first); s += ','; s+= Utils::to_string(_t.second); s+= '\n';

    for (int i = 0; i < _states.size(); i++) {
        if (_states[i].size() <= 0)
            continue;

        int n = _states[i].size() - 1;
        for (int j = 0; j < n; j++) {
            s += Utils::to_string(_states[i][j]->getCost());
            s += " ";
        }
        s += Utils::to_string(_states[i][n]->getCost());
        s += '\n';

    }
    s = s.substr(0, s.length() - 1);
    return  s;
}



State<pair<int, int>> CubeSearch::getInitialState() const {
   return *_states[_s.first][_s.second];
}

State<pair<int, int>> CubeSearch::getGoalState() const {
    return *_states[_t.first][_t.second];
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
    if (j != _M - 1) {

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
