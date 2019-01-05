//
// Created by omri on 1/2/19.
//

#include "FileCacheManager.h"
template<class Problem, class Solution>
bool FileCacheManager<Problem, Solution>::isSolutionExists(const Problem &p) const {
    return false;
}

template<class Problem, class Solution>
Solution FileCacheManager<Problem, Solution>::getSolution(const Problem &p) const {
    return nullptr;
}

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::saveSolution(const Problem &p, const Solution &s) const {

}