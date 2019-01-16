//
// Created by galpolitzer6 on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_BFS_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_BFS_H


#include <deque>

template <class Solution>
class TestSearcher : public Searcher<Solution>{
private:
    int _evaluated ;
public:

    TestSearcher() : _evaluated(0) {};

    Path<Solution>* search(Searchable<Solution>& searchable) {


        State<Solution>* s = searchable.getInitialState();
        while (s->getState() != searchable.getGoalState()->getState()) {
            vector<State<Solution>*> aps = searchable.getAllPossibleStates(s);
            _evaluated++;
            State<Solution>* r = s;
            s = aps[0];
            s->setCameFrom(r);

        }
        return this->backTrace(searchable.getGoalState());





    }
    int getNumberOfNodesEvaluated() const override {
        _evaluated;
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

    virtual ~TestSearcher() {}
};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_BFS_H
