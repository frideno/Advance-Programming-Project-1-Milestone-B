//
// Created by omri on 1/2/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_SERVER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_SERVER_H

#include "ClientHandler.h"

namespace server_side {

  class Server {

  public:
      // opens a server socket at the specified port @port.
      virtual void open(int port, ClientHandler& clientHandler) = 0;

      // closes the server.
      virtual void stop() = 0;

      // ... (maybe more)

      //virtual ~Server();
  };


};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_SERVER_H
