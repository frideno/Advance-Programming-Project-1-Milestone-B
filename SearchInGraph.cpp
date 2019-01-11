//
// Created by omri on 1/11/19.
//

#include "SearchInGraph.h"

SearchInGraph::SearchInGraph(const WeightedGraph &g, int source, int target) {

    _s = source;
    _t = target;

    int n = g.getSize();
    vector<vector<int>> m = g.getAdjMatrix();

    for (int i = 0; i < n; i++) {
        State<int> state(i);
        _states.push_back(state);
        _adjList.push_back(vector<State<int>>());
    }
    _states[_s].setCost(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (m[i][j] > 0) {

                // sets the edge i-j with cost w  = m[i][j].
                State<int> x(_states[j]);
                x.setCost(m[i][j]);
                x.setCameFrom(&_states[i]);
                _adjList[i].push_back(x);

            }
        }
    }


}

State<int> SearchInGraph::getInitialState() const {
    return _states[_s];
}

State<int> SearchInGraph::getGoalState() const {
    return _states[_t];
}

vector<State<int>> SearchInGraph::getAllPossibleStates(State<int> s) {
    return _adjList.at(s.getState());
}
