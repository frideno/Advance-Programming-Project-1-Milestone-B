//
// Created by galpolitzer6 on 1/10/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_ABSTRACTSEARCHER_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_ABSTRACTSEARCHER_H


#include "Searcher.h"
#include "StateCompare.h"
#include <algorithm>
#include <set>


/**
 * this abstract class is a base to many algorithms, based on a priority_queue
 *
 * @tparam Solution
 */

template <class Solution, class Contained = State<Solution>*>
class AbstractSearcher : public Searcher<Solution>
{

protected:

    //int to mark how many nodes have we evaluated in the search.
    int _evaluated;

public:

    //default constructor
    AbstractSearcher() : _evaluated(0) {}

    //returns the number of nodes evaluated during the search.
    int getNumberOfNodesEvaluated() const {
        return _evaluated;
    }

    //the most important function! the actual search for the solution in a given searchable object!
    virtual Path<Solution>* search(Searchable<Solution>& searchable) = 0;

protected:



    //checks if a given state is in the closed database.
    virtual bool isInClosed(std::set<State<Solution>*, StateCompare<Solution>>& _closed ,State<Solution>* s) {
        return std::find(_closed.begin(), _closed.end(), s) != _closed.end();
    }

    //adding the given state to the closed database.
    virtual void addToClosed(std::set<State<Solution>*, StateCompare<Solution>>& _closed ,State<Solution>* s) {
        _closed.insert(s);
    }

    virtual Path<Solution>* backTrace(State<Solution> *s) {

        // the path parameters.
        std::deque<Solution> q;
        double pathCost = 0;

        State<Solution>* current = s;
        while (current != nullptr) {

            pathCost += current->getCost();
            q.push_front(current->getState());
            current = current->getCameFrom();
        }
        vector<Solution> path(q.begin(), q.end());
        return new Path<Solution>(path, pathCost);
    }

};



#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_ABSTRACTSEARCHER_H