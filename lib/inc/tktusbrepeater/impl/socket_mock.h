#ifndef TKTUSBREPEATER_IMPL_SOCKET_MOCK_H
#define TKTUSBREPEATER_IMPL_SOCKET_MOCK_H

#include "tktusbrepeater/impl/socket.h"
#include <vector>

// initializeSocketImpl()
extern int  returnsInitializeSocketImpl;

// connectSocketImpl()
struct ArgsConnectSocketImpl
{
    int                 socket = 0;
    const std::string * pathPtr = nullptr;
};

extern int  calledCountConnectSocketImpl;

extern ArgsConnectSocketImpl    argsConnectSocketImpl;

extern bool returnsConnectSocketImpl;

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
    int                 socket = 0;
    std::vector< char > data;
};

extern int  calledCountWriteSocketImpl;

extern ArgsWriteSocketImpl  argsWriteSocketImpl;

extern int  returnsWriteSocketImpl;


void initializeSocketMock(
);

#endif  // TKTUSBREPEATER_IMPL_SOCKET_MOCK_H
