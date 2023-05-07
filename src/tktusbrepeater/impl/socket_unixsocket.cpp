#include "tktusbrepeater/impl/socket.h"
#include <string>
#include <sys/socket.h>
#include <cerrno>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

void closeSocketImpl(
    int _socket
)
{
    close( _socket );
}

int initializeSocketImpl(
)
{
    const auto  SOCKET = socket(
        AF_UNIX
        , SOCK_STREAM
        , 0
    );
    if( SOCKET < 0 ) {
        auto    stringStream = std::stringstream();

        stringStream << "socket()が失敗 : " << errno;

        throw std::runtime_error( stringStream.str() );
    }

    return SOCKET;
}

void bindSocketImpl(
    int                     _socket
    , const std::string &   _PATH
)
{
    //TODO
}

void listenSocketImpl(
    int _socket
)
{
    //TODO
}

int acceptSocketImpl(
    int _socket
)
{
    //TODO
    return -1;
}
