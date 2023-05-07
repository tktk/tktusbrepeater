#ifndef TKTUSBREPEATER_SERVERSOCKET_H
#define TKTUSBREPEATER_SERVERSOCKET_H

#include "tktusbrepeater/impl/socket.h"
#include <string>
#include <memory>

class ServerSocket
{
    int                 socket;
    SocketImplCloser    socketCloser;

public:
    ServerSocket(
        const std::string &
    );

    int accept(
    );
};

using ServerSocketUnique = std::unique_ptr< ServerSocket >;

ServerSocketUnique newServerSocket(
    const std::string &
);

#endif  // TKTUSBREPEATER_SERVERSOCKET_H
