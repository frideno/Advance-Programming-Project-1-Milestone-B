//
// Created by omri on 1/2/19.
//

#include "FileCacheManager.h"
#include "exceptions.h"
#include <fstream>

#define SEPERATOR "$"

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
    string key, value, line;
    string* gain = &key;
    bool keyIsOn = true;

    while (getline(file, line)) {

        if (line != SEPERATOR)
        {
            *(gain) += line;
            *(gain) += '\n';
        }
        else {
            if (keyIsOn) {

                keyIsOn = false;
                gain = &value;
            } else {
                key = key.substr(0, key.length() - 1);
                value = value.substr(0, value.length() - 1);
                saveSolution(key, value);
                keyIsOn = true;
                gain = &key;
                value = "";
                key = "";
            }
        }

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
        file << mapItem.first  << endl << SEPERATOR << endl << mapItem.second << endl << SEPERATOR << endl;
    }    
    file.close();
}

bool FileCacheManager::hasSolution(const std::string &problem) const {

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


