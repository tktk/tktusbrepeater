#include "tktusbrepeater/impl/socket_mock.h"

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

int calledCountBindSocketImpl;

ArgsBindSocketImpl  argsBindSocketImpl;

void bindSocketImpl(
    int                     _socket
    , const std::string &   _PATH
)
{
    calledCountBindSocketImpl++;

    argsBindSocketImpl.socket = _socket;
    argsBindSocketImpl.pathPtr = &_PATH;
}

int calledCountListenSocketImpl;

ArgsListenSocketImpl    argsListenSocketImpl;

void listenSocketImpl(
    int _socket
)
{
    calledCountListenSocketImpl++;

    argsListenSocketImpl.socket = _socket;
}

int calledCountAcceptSocketImpl;

ArgsAcceptSocketImpl    argsAcceptSocketImpl;

int returnsAcceptSocketImpl;

int acceptSocketImpl(
    int _socket
)
{
    calledCountAcceptSocketImpl++;

    argsAcceptSocketImpl.socket = _socket;

    return returnsAcceptSocketImpl;
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
    argsWriteSocketImpl.data = _DATA;
    argsWriteSocketImpl.dataSize = _DATA_SIZE;

    return returnsWriteSocketImpl;
}

namespace {
    void initializeMockInitializeSocketImpl(
    )
    {
        returnsInitializeSocketImpl = 0;
    }

    void initializeMockBindSocketImpl(
    )
    {
        calledCountBindSocketImpl = 0;
        argsBindSocketImpl = ArgsBindSocketImpl();
    }

    void initializeMockListenSocketImpl(
    )
    {
        calledCountListenSocketImpl = 0;
        argsListenSocketImpl = ArgsListenSocketImpl();
    }

    void initializeMockAcceptSocketImpl(
    )
    {
        calledCountAcceptSocketImpl = 0;
        argsAcceptSocketImpl = ArgsAcceptSocketImpl();
        returnsAcceptSocketImpl = 0;
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
    initializeMockBindSocketImpl();
    initializeMockListenSocketImpl();
    initializeMockAcceptSocketImpl();
    initializeMockReadSocketImpl();
    initializeMockWriteSocketImpl();
}
