//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H

/**
 * CacheManager interface represents an cache memory that can be implemented in many ways.
 */
#include <string>

class CacheManager {

public:
    // return true if solution exists to given problem.
    virtual bool isSolutionExists(const std::string& problem) const = 0;

    // get a solution for a given problem.
    virtual std::string getSolution(const std::string& problem) const = 0;

    // save a solution for a problem.
    virtual void saveSolution(const std::string& problem, const std::string& solution) = 0;

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_CACHEMANAGER_H
