//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public server_side::Server {

    void open(int port, const ClientHandler &clientHandler) override;

    void stop() override;
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
