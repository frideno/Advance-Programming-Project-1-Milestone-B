//
// Created by omri on 1/13/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSOLVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"

template <class Solution>
class SearcherSolver: Solver<Searchable<Solution>, Path<Solution>> {

private:
    Searcher<Solution> searcher;
public:

    Path<Solution> solve(Searchable<Solution> s) override {
        return searcher.search(s);
    }
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHERSOLVER_H
