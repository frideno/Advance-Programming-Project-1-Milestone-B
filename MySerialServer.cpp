//
// Created by omri on 1/2/19.
//

#include "MySerialServer.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
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
    clients.detach();

}

void MySerialServer::_loopOverClients(ClientHandler &clientHandler) {

    while (_running) {
        int client_sock;
        listen(_socketfd, 5);
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);

        timeval timeout;
        timeout.tv_sec = _timeoutSec;// _timeoutSec seconds timout.

        setsockopt(client_sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        // accepting a socket for the client to conncet.

        client_sock = accept(_socketfd, (struct sockaddr *) &client, &clilen);
        if (client_sock < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                exit(2);
            } else {
                perror("other error");
                exit(3);
            }
        }

        // handle the client as the client handler wants.
        clientHandler.handleClient(client_sock);

        // closes the client socket.
        close(client_sock);
    }

}






















//    // starts the server up:
//
//    int sockFD;
//    char buffer[256];
//    struct sockaddr_in serv_addr;
//    int n, rc;
//    int  queueMaxSize = 32;
//
//
//    /* First call to socket() function */
//    sockFD = socket(AF_INET, SOCK_STREAM, 0);
//
//    if (sockFD < 0) {
//        throw exceptionsLibrary::ServerException("ERROR opening socket");
//
//    }
//
//    /* Initialize socket structure */
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//
//    serv_addr.sin_family = AF_INET;
//    serv_addr.sin_addr.s_addr = INADDR_ANY;
//    serv_addr.sin_port = htons(port);
//
//    /* Now bind the host address using bind() call.*/
//    if (bind(sockFD, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
//        close(sockFD);
//        throw exceptionsLibrary::ServerException("ERROR on binding");
//
//    }
//    // runs an infinite loop that listen to clients one by one:, in other thread.
//
//    listen(sockFD, queueMaxSize);
//    if (rc < 0)
//    {
//        close(sockFD);
//        throw exceptionsLibrary::ServerException("listen() failed");
//    }
//
//
//    // iterating over clients in other thread.
//    thread t(&MySerialServer::_loopOverClients, this,  sockFD, ref(clientHandler));
//    t.join();

//}

//void MySerialServer::_loopOverClients(int sockFD, ClientHandler &clientHandler) {

//    struct sockaddr_in clientAddress;
//    int client, clientSocketFD, maxSD, rc;
//    fd_set   master_set, working_set;
//    struct timeval timeout;
//
//
//
//    // Initialize the master fd_set
//
//    FD_ZERO(&master_set);
//    maxSD = sockFD;
//    FD_SET(sockFD, &master_set);
//
//
//    /*
//    * Initialize the timeval struct to timeout minutes. If no
//    * activity after 3 minutes this program will end.
//    */
//
//    timeout.tv_sec  = 60 * _timeoutMin;
//    timeout.tv_usec = 0;
//
//    /*
//    * start listening for the clients, here process will
//    * go in sleep mode and will wait for the incoming connection.
//
//    * if we timeout, we close the server.
//    */
//
//    while (_running) {
//
//
//
//            // Copy the master fd_set over to the working fd_set.
//
//            memcpy(&working_set, &master_set, sizeof(master_set));
//
//            // Call select() and wait timeout minutes for it to complete.
//
//            rc = select(maxSD + 1, &working_set, NULL, NULL, &timeout);
//
//            // Check to see if the select call failed.
//            if (rc < 0)
//            {
//                perror("  select() failed");
//                break;
//            }
//
//
//
//        /* Accept actual connection from the client */
//        clientSocketFD = accept(sockFD, (struct sockaddr *) &clientAddress, (socklen_t *) &client);
//
//
//        if (clientSocketFD < 0) {
//            close(sockFD);
//            throw exceptionsLibrary::ServerException("ERROR on accept");
//
//        }
//
//        // handle the client as the clientHandler intended.
//        clientHandler.handleClient(clientSocketFD, clientSocketFD);   // in TCP we use the same socket for writing and reading.
//
//        // close the connection with this client.
//        close(clientSocketFD);
//    }
//}

void MySerialServer::stop() {

    close(_socketfd);
    _running = false;
}

MySerialServer::~MySerialServer() {

    stop();

}



