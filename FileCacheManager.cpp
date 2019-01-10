//
// Created by omri on 1/2/19.
//

#include "FileCacheManager.h"
#include "exceptions.h"
#include <fstream>

FileCacheManager::FileCacheManager(string fileName) {
    cache = unordered_map<string, string>();
    cacheFileName = fileName;
    
    ifstream file;
    file.open(fileName);
    
    // if failed to open file.
    if (!file.is_open()) {
        throw exceptionsLibrary::BasicException("cache file does'nt exsists.");
    }
    
    // Reads map from the file.
    string key, value;
    while (file.peek() != EOF) {    
        // entering key - value to map:
        file >> key >> value;
        saveSolution(key, value);
        
    }
    file.close();
}

FileCacheManager::~FileCacheManager() {
    // writes cache map to file:
    ofstream file;
    file.open(cacheFileName);
    if (!file.is_open()) {
        throw("cache file does'nt exsists.");
    }
    
    // saving the map to the file.
    for (auto const& mapItem : cache) {
        file << mapItem.first  << endl << mapItem.second << endl;
    }    
    file.close();
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


