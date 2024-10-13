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

// readSocketImpl()
struct ArgsReadSocketImpl
{
    int     socket = 0;
    void *  data = nullptr;
    int     dataSize = 0;
};

extern int  calledCountReadSocketImpl;

extern ArgsReadSocketImpl   argsReadSocketImpl;

extern int  returnsReadSocketImpl;

// writeSocketImpl()
struct ArgsWriteSocketImpl
{
    int             socket = 0;
    const void *    data = nullptr;
    int             dataSize = 0;
};

extern int  calledCountWriteSocketImpl;

extern ArgsWriteSocketImpl  argsWriteSocketImpl;

extern int  returnsWriteSocketImpl;

// isConnectedSocketImpl()
struct ArgsIsConnectedSocketImpl
{
    int socket = 0;
};

extern int  calledCountIsConnectedSocketImpl;

extern ArgsIsConnectedSocketImpl    argsIsConnectedSocketImpl;

extern bool returnsIsConnectedSocketImpl;

// pollInSocketImpl()
struct ArgsPollInSocketImpl
{
    int socket = 0;
    int timeout = 0;
};

extern int  calledCountPollInSocketImpl;

extern ArgsPollInSocketImpl argsPollInSocketImpl;

extern bool returnsPollInSocketImpl;

// pollOutSocketImpl()
struct ArgsPollOutSocketImpl
{
    int socket = 0;
    int timeout = 0;
};

extern int  calledCountPollOutSocketImpl;

extern ArgsPollOutSocketImpl    argsPollOutSocketImpl;

extern bool returnsPollOutSocketImpl;


void initializeSocketMock(
);

#endif  // TKTUSBREPEATER_IMPL_SOCKET_MOCK_H
