//
// created by omri & gal on 12/25/18.
//

#ifndef PROG1PROJECT_EXCEPTIONS_H
#define PROG1PROJECT_EXCEPTIONS_H

#include <exception>
#include <string>

namespace exceptionsLibrary {
class BasicException : public std::exception {
    protected:
        std::string _message;

    public :
        explicit BasicException(std::string message) :
                _message(message) {}

        virtual const char *what() const throw() {
            return _message.c_str();
        }

        virtual ~BasicException() {

        }

    };


    class SymbolException : public BasicException {
    public :
        explicit SymbolException(std::string message) :
                BasicException(message) {};
    };


    class DevisionByZeroException : public BasicException {
    public :
        explicit DevisionByZeroException(std::string m) :
                BasicException(m) {};
    };


    class ServerException : public BasicException {
    public :
        explicit ServerException(std::string message) :
                BasicException(message) {};
    };

    class ClientHandlerException : public ServerException {
    public :
        explicit ClientHandlerException(std::string message) :
                ServerException(message) {};
    };


    class TimeoutException : public ServerException {
    public :
        explicit TimeoutException(std::string message) :
                ServerException(message) {};
    };



};
#endif //PROG1PROJECT_EXCEPTIONS_H