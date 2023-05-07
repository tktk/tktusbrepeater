#ifndef TKTUSBREPEATER_IMPL_SOCKET_MOCK_H
#define TKTUSBREPEATER_IMPL_SOCKET_MOCK_H

#include "tktusbrepeater/impl/socket.h"

// initializeSocketImpl()
extern int  returnsInitializeSocketImpl;

// bindSocketImpl()
struct ArgsBindSocketImpl
{
    int                 socket = 0;
    const std::string * pathPtr = nullptr;
};

extern int  calledCountBindSocketImpl;

extern ArgsBindSocketImpl   argsBindSocketImpl;

// listenSocketImpl()
struct ArgsListenSocketImpl
{
    int socket = 0;
};

extern int  calledCountListenSocketImpl;

extern ArgsListenSocketImpl argsListenSocketImpl;

// acceptSocketImpl()
struct ArgsAcceptSocketImpl
{
    int socket = 0;
};

extern int  calledCountAcceptSocketImpl;

extern ArgsAcceptSocketImpl argsAcceptSocketImpl;

extern int  returnsAcceptSocketImpl;


void initializeSocketMock(
);

#endif  // TKTUSBREPEATER_IMPL_SOCKET_MOCK_H
