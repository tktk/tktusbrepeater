#ifndef TKTUSBREPEATER_IMPL_SOCKET_H
#define TKTUSBREPEATER_IMPL_SOCKET_H

#include <string>
#include <memory>
#include <cstddef>

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
    , const char *
    , std::size_t
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

#endif  // TKTUSBREPEATER_IMPL_SOCKET_H
