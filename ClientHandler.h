//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_CLIENTHANDLER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_CLIENTHANDLER_H

#include <iosfwd>
using namespace std;

/**
 * this class handles the client side, that can be changing for each time.
 */
class ClientHandler {

public:

    virtual void handleClient(int socket) = 0;

    virtual ~ClientHandler() {};
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_CLIENTHANDLER_H
