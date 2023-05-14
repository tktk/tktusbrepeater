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
        addrUn.sun_path + 1
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
    if( listen(
        _socket
        , 1
    ) < 0 ) {
        auto    stringStream = std::stringstream();

        stringStream << "listen()が失敗 : " << errno;

        throw std::runtime_error( stringStream.str() );
    }
}

int acceptSocketImpl(
    int _socket
)
{
    return accept(
        _socket
        , nullptr
        , nullptr
    );
}

int readSocketImpl(
    int         _socket
    , void *    _data
    , int       _DATA_SIZE
)
{
    return read(
        _socket
        , _data
        , _DATA_SIZE
    );
}

int writeSocketImpl(
    int             _socket
    , const void *  _DATA
    , int           _DATA_SIZE
)
{
    return write(
        _socket
        , _DATA
        , _DATA_SIZE
    );
}
