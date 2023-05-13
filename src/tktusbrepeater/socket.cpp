#include "tktusbrepeater/socket.h"

Socket::Socket(
    int _socket
)
    : socket( _socket )
    , socketCloser( &( this->socket ) )
{
}

int Socket::read(
    void *  _data
    , int   _DATA_SIZE
)
{
    //TODO
    return -1;
}

int Socket::write(
    const void *    _DATA
    , int           _DATA_SIZE
)
{
    //TODO
    return -1;
}

SocketUnique newSocket(
    int _socket
)
{
    return SocketUnique( new Socket( _socket ) );
}
