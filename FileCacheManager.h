//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H


#include "CacheManager.h"

template < class Problem, class Solution>
        class FileCacheManager: public CacheManager<Problem, Solution> {
            bool isSolutionExists(const Problem &p) const override;

            Solution getSolution(const Problem &p) const override;

            void saveSolution(const Problem &p, const Solution &s) const override;

        };




#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H
