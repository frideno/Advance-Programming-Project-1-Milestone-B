//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <unordered_map>

using namespace std;

class FileCacheManager: public CacheManager {

private:
        unordered_map<string&, string&> cache;    // O(1) average search map, O(N) worse case.

public:

    bool isSolutionExists(const std::string &problem) const override;

    std::string getSolution(const std::string &problem) const override;

    void saveSolution(const std::string &problem, const std::string &solution) override;


};




#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_FILECACHEMANAGER_H
