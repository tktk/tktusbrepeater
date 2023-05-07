#ifndef TKTUSBREPEATER_SERVERSOCKET_TEST_H
#define TKTUSBREPEATER_SERVERSOCKET_TEST_H

#include "tktusbrepeater/impl/socket.h"

struct ServerSocketImpl
{
    int                 socket;
    SocketImplCloser    socketCloser;
};

#endif  // TKTUSBREPEATER_SERVERSOCKET_TEST_H
