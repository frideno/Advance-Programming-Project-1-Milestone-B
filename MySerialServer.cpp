//
// Created by omri on 1/2/19.
//

#include "MySerialServer.h"
#include "exceptions.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <functional>
#include <thread>

MySerialServer::MySerialServer()
        : _running(true), _timeoutSec(600) {}

MySerialServer::MySerialServer(double t)
        : _running(true), _timeoutSec(t) {}


void MySerialServer::open(int port, ClientHandler &clientHandler) {

    // opening new socket:
    _socketfd = socket(AF_INET, SOCK_STREAM, 0);

    // making a sockaddr with the port given ,as TCP
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;

    // binds the socket and the address.
    if (bind(_socketfd, (sockaddr * ) & serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }


    // run the clients handling loop in other thread.

    thread clients(&MySerialServer::_loopOverClients, this,  ref(clientHandler));
    clients.join();

}

void MySerialServer::_loopOverClients(ClientHandler &clientHandler) {

    bool notFirst = false;
    while (myMutex.try_lock() &&_running) {

        myMutex.unlock();
        int client_sock;
        listen(_socketfd, 5);
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);

        // accepting a socket for the client to conncet.

        int opt = 3;
        setsockopt(_socketfd, SOL_SOCKET, SO_RCVLOWAT,&opt,sizeof(opt));


        struct timeval timeout;
        timeout.tv_sec = _timeoutSec;// _timeoutSec seconds timout.
        timeout.tv_usec = 0;


        // if its not the first round in loop, sets a timeout.
        if (notFirst) {

            fd_set fdSet;
            FD_ZERO(&fdSet);
            FD_SET(_socketfd,&fdSet);

            int ret = select(_socketfd + 1 ,&fdSet, NULL, NULL, &timeout);
            if (ret <= 0) // timeout
            {
                stop();
                return;
            }

        } else {
            notFirst = true;
        }

        client_sock = accept(_socketfd, (struct sockaddr *) &client, &clilen);
        if (client_sock < 0) {
            if (errno == EWOULDBLOCK) {
                stop();
                return;
            } else {
                throw exceptionsLibrary::ServerException("other server error");

            }
        }

        // setting timeout for client input.
        //timeout.tv_sec = 20;
        //setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        // handle the client as the client handler wants.
        try {
            clientHandler.handleClient(client_sock);
        } catch (exceptionsLibrary::ClientHandlerException) {

            close(client_sock);
            continue;
        } catch (...) {
            close(client_sock);
            stop();
            return;
        }

        // closes the client socket.
        close(client_sock);
    }
    // opening the lock if locked.
    myMutex.unlock();
}


void MySerialServer::stop() {

    close(_socketfd);

    // setting the running to false under locking it.
    myMutex.lock();
    _running = false;
    myMutex.unlock();
}

MySerialServer::~MySerialServer() {

    stop();

}



