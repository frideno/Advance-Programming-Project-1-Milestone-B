//
// Created by omri on 1/10/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H


#include "ClientHandler.h"

class SearchProblemClientHandler: public ClientHandler {


public:

    void handleClient(int inSocket, int outSocket) override;

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SEARCHPROBLEMCLIENTHANDLER_H
