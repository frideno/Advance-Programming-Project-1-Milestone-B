//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCED_PROGRAMMING_1_MILESTONE_2_BFS_H
#define ADVANCED_PROGRAMMING_1_MILESTONE_2_BFS_H

#include "AbstractSearcher.h"


template <class Solution>
class BFS : public AbstractSearcher<Solution> {

public:

    BFS() : AbstractSearcher<Solution>() {}

    virtual ~BFS() {}

    Path<Solution>* search(Searchable<Solution>& searchable) override {


        //database for the "done with" states.
        std::set<State<Solution>*, StateCompare<Solution>> _closed;

        std::queue<State<Solution>*> _open;


        _open.push(searchable.getInitialState());
        while (!_open.empty()) {
            State<Solution>* current = this->popOpen(_open);
            if (current == searchable.getGoalState()) {
                return this->backTrace(current);
            }
            vector<State<Solution>*> successors = searchable.getAllPossibleStates(current);
            for (unsigned long i = 0; i < successors.size(); i++) {
                State<Solution>* successor = successors[i];
                if (this->isInClosed(_closed,successor)) {
                    continue;
                }
                if (!(isInOpen(_open,successor))) {
                    successor->setCameFrom(current);
                    _open.push(successor);
                }
            }
            this->addToClosed(_closed,current);
        }
        return new Path<Solution>();
    }

private:

    State<Solution>* popFromOpen(std::queue<State<Solution>*>& _open)  {

        State<Solution>* s = _open.front();
        _open.pop();
        return s;

    }

    bool isInOpen(queue<State<Solution>*>& _open, State<Solution> *s) {
        return findInOpen(_open,s) != nullptr;
    }

private:

    State<Solution> *findInOpen(queue<State<Solution>*>& _open,State<Solution> *s) {
        std::queue<State<Solution>*> temp;
        State<Solution>* found;
        bool isFound = false;
        while (!_open.empty()) {
            found = _open.front();
            temp.push(found);
            _open.pop();
            if (*found == *s) {
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

        return nullptr;
    }
    //returns the state with the most important priority in the open database.
    State<Solution>* popOpen(std::queue<State<Solution>*>& _open) {

        AbstractSearcher<Solution>::_evaluated++;

        State<Solution>* s = popFromOpen(_open);
        return s;
    }
};

#endif //ADVANCED_PROGRAMMING_1_MILESTONE_2_BFS_H

