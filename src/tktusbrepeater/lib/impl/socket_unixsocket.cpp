#include "tktusbrepeater/impl/socket.h"
#include <cstddef>
#include <cstring>
#include <sys/socket.h>
#include <sys/un.h>
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
    return socket(
        AF_UNIX
        , SOCK_STREAM
        , 0
    );
}

bool connectSocketImpl(
    int             _socket
    , const char *  _PATH
    , std::size_t   _PATH_SIZE
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
        , _PATH
        , _PATH_SIZE
    );

    return connect(
        _socket
        , reinterpret_cast< sockaddr * >( &addrUn )
        , sizeof( addrUn )
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
