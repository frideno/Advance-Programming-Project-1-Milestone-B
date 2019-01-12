//
// Created by omri on 1/10/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H


#include "ClientHandler.h"
#include "CacheManager.h"
#include "CubeSearch.h"
#include "Path.h"
#include "Searcher.h"

class SearchProblemClientHandler: public ClientHandler {

private:

    // a cache manager for the problems and solutions.
    CacheManager* cacheManager;

    // a solver to solve the problems.
    Searcher<pair<int, int>>* _searcher;

    CubeSearch* buildGraph(string &str);

    string pathToDirections(Path<pair<int, int>>* path);

public:


    // constructor.
    SearchProblemClientHandler();

    void handleClient(int socket) override;

    ~SearchProblemClientHandler();

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H
