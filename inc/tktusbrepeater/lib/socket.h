#ifndef TKTUSBREPEATER_LIB_SOCKET_H
#define TKTUSBREPEATER_LIB_SOCKET_H

#include <string>
#include <memory>

void closeSocketImpl(
    int
);

struct CloseSocketImpl
{
    void operator()(
        int *   _socketPtr
    ) const
    {
        closeSocketImpl( *_socketPtr );
    }
};

using SocketImplCloser= std::unique_ptr<
    int
    , CloseSocketImpl
>;

int initializeSocketImpl(
);

bool connectSocketImpl(
    int
    , const std::string &
);

int readSocketImpl(
    int
    , void *
    , int
);

int writeSocketImpl(
    int
    , const void *
    , int
);

#endif  // TKTUSBREPEATER_LIB_SOCKET_H
