//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public server_side::Server {

private:
    bool _running;

    float _timeoutMin;

    // loop over the clients in serial form on teh socket by socketfd, with the clientHandler.
    void _loopOverClients(int socketfd, ClientHandler& clientHandler);
public:
    MySerialServer();

    void open(int port, ClientHandler &clientHandler) override;

    void stop() override;

    ~MySerialServer();
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_MYSERIALSERVER_H
