//
// Created by galpolitzer6 on 1/11/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_A_STAR_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_A_STAR_H


#include <queue>
#include <cmath>
#include "AbstractSearcher.h"
#include "HeuristicCompare.h"
#include "SimpleCompare.h"
template <class Solution>
class A_Star: public AbstractSearcher<Solution, SearcherState<Solution>> {

public:

    A_Star() : AbstractSearcher<Solution, SearcherState<Solution>>() {}

    virtual ~A_Star() {}


    Path<Solution>* search(Searchable<Solution> &searchable) override {


        //database for the "done with" states.
        std::set<State<Solution>*, StateCompare<Solution>> _closed;;

        std::priority_queue<SearcherState<Solution>, vector<SearcherState<Solution>>, SimpleCompare<Solution>> _open;
        
        _open.push(SearcherState<Solution>(searchable.getInitialState(), 0));
        while (!_open.empty()) {
            SearcherState<Solution> current = this->popOpen(_open);
            this->addToClosed(_closed,current.getWrappedState());
            if (*(current.getWrappedState()) == *searchable.getGoalState()) {
                return this->backTrace(current.getWrappedState());
            }
            vector<State<Solution> *> successors = searchable.getAllPossibleStates(current.getWrappedState());
            for (unsigned long i = 0; i < successors.size(); i++) {
                State<Solution> *successor = successors[i];
                if (successor->getCost() == INFINITY) {
                    continue;
                }
                if (this->isInClosed(_closed,successor)) {
                    continue;       // Ignore the neighbor which is already evaluated.
                }
                if (!this->isInOpen(_open,successor)) {             // Discover a new node
                    successor->setCameFrom(current.getWrappedState());
                    _open.push(SearcherState<Solution>(successor, current.getTotalCost() + successor->getCost()));
                } else {
                    SearcherState<Solution> successorInOpen = this->findInOpen(_open,successor);
                    if (current.getTotalCost() + successor->getCost() >= successorInOpen.getTotalCost()) {
                        continue;
                    }
                    // This path is the best until now. Record it!
                    successorInOpen.getWrappedState()->setCameFrom(current.getWrappedState());
                    successorInOpen.setTotalCost(current.getTotalCost() + successor->getCost());
                }
            }
        }

        return new Path<Solution>();
    }

private:

    SearcherState<Solution> popFromOpen(std::priority_queue<SearcherState<Solution>, vector<SearcherState<Solution>>, SimpleCompare<Solution>>& _open)  {

        SearcherState<Solution> s = _open.top();
        _open.pop();
        return s;

    }

    bool isInOpen(std::priority_queue<SearcherState<Solution>, vector<SearcherState<Solution>>, SimpleCompare<Solution>>& _open,State<Solution> *s) {
        return findInOpen(_open,s) != SearcherState<Solution>();
    }

    SearcherState<Solution> findInOpen(std::priority_queue<SearcherState<Solution>, vector<SearcherState<Solution>>, SimpleCompare<Solution>>& _open, State<Solution> *s)  {
        std::queue<SearcherState<Solution>> temp;
        SearcherState<Solution> found;
        bool isFound = false;
        while (!_open.empty()) {
            found = _open.top();
            temp.push(found);
            _open.pop();
            if (*(found.getWrappedState()) == *s) {
                isFound = true;
                break;
            }
        }
        while (!temp.empty()) {
            _open.push(temp.front());
            temp.pop();
        }
        if (isFound) {
            return found;
        }

        return SearcherState<Solution>();
    }

    //returns the state with the most important priority in the open database.
    SearcherState<Solution> popOpen(std::priority_queue<SearcherState<Solution>, vector<SearcherState<Solution>>, SimpleCompare<Solution>>& _open) {

        this->_evaluated++;
        SearcherState<Solution> s = popFromOpen(_open);
        return s;
    }
};

#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_A_STAR_H
