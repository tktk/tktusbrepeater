#include "tktusbrepeater/lib/impl/socket_mock.h"

void closeSocketImpl(
    int
)
{
}

int returnsInitializeSocketImpl;

int initializeSocketImpl(
)
{
    return returnsInitializeSocketImpl;
}

int calledCountConnectSocketImpl;

ArgsConnectSocketImpl   argsConnectSocketImpl;

bool    returnsConnectSocketImpl;

bool connectSocketImpl(
    int             _socket
    , const char *  _PATH
)
{
    calledCountConnectSocketImpl++;

    argsConnectSocketImpl.socket = _socket;
    argsConnectSocketImpl.pathPtr = _PATH;

    return returnsConnectSocketImpl;
}

int calledCountReadSocketImpl;

ArgsReadSocketImpl  argsReadSocketImpl;

int returnsReadSocketImpl;

int readSocketImpl(
    int         _socket
    , void *    _data
    , int       _DATA_SIZE
)
{
    calledCountReadSocketImpl++;

    argsReadSocketImpl.socket = _socket;
    argsReadSocketImpl.data = _data;
    argsReadSocketImpl.dataSize = _DATA_SIZE;

    return returnsReadSocketImpl;
}

int calledCountWriteSocketImpl;

ArgsWriteSocketImpl argsWriteSocketImpl;

int returnsWriteSocketImpl;

int writeSocketImpl(
    int             _socket
    , const void *  _DATA
    , int           _DATA_SIZE
)
{
    calledCountWriteSocketImpl++;

    argsWriteSocketImpl.socket = _socket;
    argsWriteSocketImpl.data.insert(
        argsWriteSocketImpl.data.end()
        , static_cast< const char * >( _DATA )
        , static_cast< const char * >( _DATA ) + _DATA_SIZE
    );

    return returnsWriteSocketImpl;
}

namespace {
    void initializeMockInitializeSocketImpl(
    )
    {
        returnsInitializeSocketImpl = 0;
    }

    void initializeMockConnectSocketImpl(
    )
    {
        calledCountConnectSocketImpl = 0;
        argsConnectSocketImpl = ArgsConnectSocketImpl();
        returnsConnectSocketImpl = false;
    }

    void initializeMockReadSocketImpl(
    )
    {
        calledCountReadSocketImpl = 0;
        argsReadSocketImpl = ArgsReadSocketImpl();
        returnsReadSocketImpl = 0;
    }

    void initializeMockWriteSocketImpl(
    )
    {
        calledCountWriteSocketImpl = 0;
        argsWriteSocketImpl = ArgsWriteSocketImpl();
        returnsWriteSocketImpl = 0;
    }
}

void initializeSocketMock(
)
{
    initializeMockInitializeSocketImpl();
    initializeMockConnectSocketImpl();
    initializeMockReadSocketImpl();
    initializeMockWriteSocketImpl();
}
