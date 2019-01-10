//
// Created by omri on 1/9/19.
//

#include <queue>
#include <set>
#include "BestFirstSearch.h"

/*
 * The Algorithm psudo code:
 *
     * Best First Search:
    OPEN = [initial state] // a priority queue of states to be evaluated
    CLOSED = [] // a set of states already evaluated
    while OPEN is not empty
    do
    1. n  dequeue(OPEN) // Remove the best node from OPEN
    2. add(n,CLOSED) // so we won’t check n again
    3. If n is the goal state,
    backtrace path to n (through recorded parents) and return path.
    4. Create n's successors.
    5. For each successor s do:
    a. If s is not in CLOSED and s is not in OPEN:
    i. update that we came to s from n
    ii. add(s,OPEN)
    b. Otherwise, if this new path is better than previous one
    i. If it is not in OPEN add it to OPEN.
    ii. Otherwise, adjust its priority in OPEN
    done
 *
 * */
template <class Solution>
Solution BestFirstSearch<Solution>::search(Searchable<Solution> &searchable) {

    priority_queue<Solution> open;
    open.push(searchable.getInitialState());
    std::set<Solution> closed;

    while(!open.empty()) {
        State<Solution> current = open.pop();
        closed.insert(current);
        if (current == searchable.getGoalState()) {            //need to implement == overloading
            return backTrace(current);
        }
        vector<State<Solution*>>
    }

}

int BestFirstSearch::getNumberOfNodesEvaluated() const {//////////////////////////////////////////////
    return _evaluated;
}

template<class Solution>
vector<State<Solution>*> BestFirstSearch<Solution>::backTrace(State<Solution> *s) {
    vector<State<Solution>*>
    while()
}
