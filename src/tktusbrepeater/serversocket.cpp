#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/impl/socket.h"

ServerSocket::ServerSocket(
    const std::string & _PATH
)
    : socket( initializeSocketImpl() )
    , socketCloser( &( this->socket ) )
{
    bindSocketImpl(
        this->socket
        , _PATH
    );

    listenSocketImpl( this->socket );
}

int ServerSocket::accept(
)
{
    return acceptSocketImpl( this->socket );
}

bool ServerSocket::pollIn(
    int _TIMEOUT
)
{
    //TODO
    return false;
}

ServerSocketUnique newServerSocket(
    const std::string & _PATH
)
{
    return ServerSocketUnique( new ServerSocket( _PATH ) );
}
