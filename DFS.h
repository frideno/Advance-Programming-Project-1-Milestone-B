//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_DFS_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_DFS_H

#include <stack>
#include <unordered_set>
#include <cmath>
#include "AbstractSearcher.h"


template <class Solution>
class DFS : public AbstractSearcher<Solution> {

public:

    DFS() : AbstractSearcher<Solution>() {}

    virtual ~DFS() {}

    Path<Solution>* search(Searchable<Solution> &searchable) override {


        //database for the "done with" states.
        std::set<State<Solution>*, StateCompare<Solution>> _closed;

        std::stack<State<Solution>*> _open;

        _open.push(searchable.getInitialState());
        while (!_open.empty()) {
            State<Solution>* current = this->popOpen(_open);
            if (*current == *searchable.getGoalState()) {
                return AbstractSearcher<Solution>::backTrace(current);
            }
            if (AbstractSearcher<Solution>::isInClosed(_closed,current)) {
                continue;
            }
            AbstractSearcher<Solution>::addToClosed(_closed,current);
            vector<State<Solution>*> successors = searchable.getAllPossibleStates(current);
            for (unsigned long i = 0; i < successors.size(); i++) {
                State<Solution>* successor = successors[i];
                if (successor->getCost() == INFINITY) {
                    continue;
                }
                if (AbstractSearcher<Solution>::isInClosed(_closed,successor)) {
                    continue;
                }
                if (isInOpen(_open,successor)) {
                    continue;
                }
                successor->setCameFrom(current);
                _open.push(successor);
            }
        }

        return new Path<Solution>();
    }

private:
    State<Solution>* popFromOpen(std::stack<State<Solution>*>& _open) {

        State<Solution>* s = _open.top();
        _open.pop();
        return s;

    }

    bool isInOpen(std::stack<State<Solution>*>& _open, State<Solution> *s)  {
        return findInOpen(_open,s) != nullptr;
    }

    State<Solution> *findInOpen(std::stack<State<Solution>*> _open, State<Solution> *s)  {
        std::stack<State<Solution>*> temp;
        State<Solution>* found;
        bool isFound = false;
        while(!_open.empty()) {
            found = _open.top();
            if (*found == *s) {
                isFound = true;
                break;
            }
            temp.push(found);
            _open.pop();
        }
        while(!temp.empty()) {
            _open.push(temp.top());
            temp.pop();
        }
        if (isFound) {
            return found;
        }
        return nullptr;
    }
    //returns the state with the most important priority in the open database.
    State<Solution>* popOpen(std::stack<State<Solution>*>& _open) {

        AbstractSearcher<Solution>::_evaluated++;

        State<Solution>* s = popFromOpen(_open);
        return s;
    }
};

#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_DFS_H
