#ifndef TKTUSBREPEATER_SOCKET_H
#define TKTUSBREPEATER_SOCKET_H

#include "tktusbrepeater/impl/socket.h"
#include <memory>

class Socket
{
    int                 socket;
    SocketImplCloser    socketCloser;

public:
    Socket(
        int
    );

    int read(
        void *
        , int
    );

    int write(
        const void *
        , int
    );
};

using SocketUnique = std::unique_ptr< Socket >;

SocketUnique newSocket(
    int
);

#endif  // TKTUSBREPEATER_SOCKET_H
