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
}

void initializeSocketMock(
)
{
    initializeMockInitializeSocketImpl();
    initializeMockBindSocketImpl();
    initializeMockListenSocketImpl();
    initializeMockAcceptSocketImpl();
}
