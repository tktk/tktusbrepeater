#ifndef TKTUSBREPEATER_SOCKET_TEST_H
#define TKTUSBREPEATER_SOCKET_TEST_H

#include "tktusbrepeater/impl/socket.h"

struct SocketImpl
{
    int                 socket;
    SocketImplCloser    socketCloser;
};

#endif  // TKTUSBREPEATER_SOCKET_TEST_H
