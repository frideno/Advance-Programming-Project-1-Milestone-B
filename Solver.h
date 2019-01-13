//
// Created by omri on 1/13/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SOLVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SOLVER_H

template <class Problem, class Solution>
class Solver {

    virtual Solution solve(Problem p) = 0;
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SOLVER_H
