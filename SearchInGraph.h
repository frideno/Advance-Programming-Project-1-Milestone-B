//
// Created by omri on 1/11/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHINGRAPH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHINGRAPH_H


#include "Searchable.h"
#include "WeightedGraph.h"
#include <map>

class SearchInGraph: public Searchable<int> {

private:

    int _s,_t;
    vector<State<int>> _states;

    vector<vector<State<int>>> _adjList;

public:

    SearchInGraph(const WeightedGraph& g, int source, int target);

    State<int> getInitialState() const override;

    State<int> getGoalState() const override;

    vector<State<int>> getAllPossibleStates(State<int> s) override;

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHINGRAPH_H
