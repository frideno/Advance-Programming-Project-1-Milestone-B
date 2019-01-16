//
// Created by omri on 1/2/19.
//

#include "FileCacheManager.h"
#include "exceptions.h"
#include <fstream>

#define SEPERATOR "$"
std::mutex mute1;


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
    // saving the map to the file.
    for (auto const& mapItem : cache) {
        file << mapItem.first  << endl << SEPERATOR << endl << mapItem.second << endl << SEPERATOR << endl;
    }    
    file.close();
}

bool FileCacheManager::hasSolution(const std::string &problem) const {

    mute1.lock();
    // returns true if the cache map has the input problem.
    bool tmp =  (cache.count(problem) != 0);

    mute1.unlock();
    return tmp;
}

std::string FileCacheManager::getSolution(const std::string &problem) const {

    // returns nullptr if the problem solution does not exsists
    mute1.lock();

    if (cache.count(problem) == 0) {
        mute1.unlock();
        return nullptr;
    }

    // else, return the solution in avergae O(1).
    string tmp = cache.at(problem);
    mute1.unlock();
    return tmp;
}

void FileCacheManager::saveSolution(const std::string &problem, const std::string &solution) {

    mute1.lock();
    // sets cache in problem to be solution.
    cache[problem] = solution;

    mute1.unlock();
}


