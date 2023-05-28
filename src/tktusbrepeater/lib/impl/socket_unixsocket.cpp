#include "tktusbrepeater/impl/socket.h"
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
)
{
    //TODO
    return false;
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
