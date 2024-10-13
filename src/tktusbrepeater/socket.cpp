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
    return readSocketImpl(
        this->socket
        , _data
        , _DATA_SIZE
    );
}

int Socket::write(
    const void *    _DATA
    , int           _DATA_SIZE
)
{
    return writeSocketImpl(
        this->socket
        , _DATA
        , _DATA_SIZE
    );
}

bool Socket::isConnected(
)
{
    return isConnectedSocketImpl( this->socket );
}

SocketUnique newSocket(
    int _socket
)
{
    return SocketUnique( new Socket( _socket ) );
}

bool Socket::pollIn(
    int _TIMEOUT_MILLISECONDS
)
{
    //TODO
    return false;
}

bool Socket::pollOut(
    int _TIMEOUT_MILLISECONDS
)
{
    //TODO
    return false;
}
