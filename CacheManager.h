//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H

/**
 * CacheManager interfase represents an cache memory that can be implemented in many ways.
 */

template < class Problem, class Solution>
class CacheManager {

    // return true if solution exists to given problem.
    virtual bool isSolutionExists(const Problem& p) const = 0;

    // get a solution for a given problem.
    virtual Solution getSolution(const Problem& p) const = 0;

    // save a solution for a problem.
    virtual void saveSolution(const Problem& p, const Solution& s) const = 0;

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H
