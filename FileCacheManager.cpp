//
// Created by omri on 1/2/19.
//

#include "FileCacheManager.h"

FileCacheManager::FileCacheManager() {

    cache = unordered_map<string, string>();
}

FileCacheManager::~FileCacheManager() {
    delete &cache;
}

bool FileCacheManager::isSolutionExists(const std::string &problem) const {

    // returns true if the cache map has the input problem.
    return (cache.count(problem) != 0);
}

std::string FileCacheManager::getSolution(const std::string &problem) const {

    // returns nullptr if the problem solution does not exsists

    if (cache.count(problem) == 0) {
        return nullptr;
    }

    // else, return the solution in avergae O(1).
    return cache.at(problem);
}

void FileCacheManager::saveSolution(const std::string &problem, const std::string &solution) {

    // sets cache in problem to be solution.
    cache[problem] = solution;
}


