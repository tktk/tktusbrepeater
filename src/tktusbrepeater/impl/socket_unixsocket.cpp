#include "tktusbrepeater/impl/socket.h"
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cerrno>
#include <sstream>
#include <stdexcept>

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
    auto    addrUn = sockaddr_un();
    std::memset(
        &addrUn
        , 0
        , sizeof( addrUn )
    );

    addrUn.sun_family = AF_UNIX;
    std::memcpy(
        addrUn.sun_path
        , _PATH.c_str()
        , _PATH.size()
    );

    if( bind(
        _socket
        , reinterpret_cast< sockaddr * >( &addrUn )
        , sizeof( addrUn )
    ) < 0 ) {
        auto    stringStream = std::stringstream();

        stringStream << "bind()が失敗 : " << errno;

        throw std::runtime_error( stringStream.str() );
    }
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
