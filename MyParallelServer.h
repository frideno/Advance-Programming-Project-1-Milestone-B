//
// Created by omri on 1/14/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_MYPARALLELSERVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_MYPARALLELSERVER_H

#include "Server.h"
#include <thread>
#include <mutex>
#include <vector>

class MyParallelServer : public server_side::Server{

private:

    // setting a mutex for multithreading
    std::mutex myMutex;

    int _socketfd;

    bool _running;

    vector<thread> clientThreads;

    double _timeoutSec;

    // loop over the clients in serial form on teh socket by socketfd, with the clientHandler.
    void _loopOverClients(ClientHandler& clientHandler);
public:
    MyParallelServer();

    MyParallelServer(double timeout);

    void open(int port, ClientHandler &clientHandler) override;

    void stop() override;

    ~MyParallelServer();
};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_MYPARALLELSERVER_H
