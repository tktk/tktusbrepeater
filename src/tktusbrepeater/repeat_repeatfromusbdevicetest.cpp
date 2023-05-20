#include "tktusbrepeater/test.h"
#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/socket.h"
#include <cstring>

namespace {
    struct ArgsBulkTransfer
    {
        UsbDeviceManager *  usbDeviceManagerPtr = nullptr;
        unsigned char       endpoint = 0;
        void *              data = nullptr;
        int                 dataSize = 0;
    };

    struct ArgsWrite
    {
        Socket *        socketPtr = nullptr;
        const void *    data = nullptr;
        int             dataSize = 0;
    };

    struct ArgsIsConnected
    {
        Socket *    socketPtr = nullptr;
    };

    auto    argsBulkTransfer = ArgsBulkTransfer();
    auto    returnsBulkTransfer = static_cast< int >( 0 );

    auto    calledWrite = static_cast< int >( 0 );
    auto    argsWrite = ArgsWrite();
    auto    returnsWrite = static_cast< int >( 0 );

    auto    calledIsConnected = static_cast< int >( 0 );
    auto    argsIsConnected = ArgsIsConnected();
    auto    returnsIsConnected = false;

    class RepeatFromUsbDeviceTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            argsBulkTransfer = ArgsBulkTransfer();
            returnsBulkTransfer = 0;

            calledWrite = 0;
            argsWrite = ArgsWrite();
            returnsWrite = 0;

            calledIsConnected = 0;
            argsIsConnected = ArgsIsConnected();
            returnsIsConnected = false;
        }

    public:
        void test(
            int     _RETURNS_BULK_TRANSFER
            , bool  _RETURNS_IS_CONNECTED
            , int   _RETURNS_WRITE
            , bool  _EXPECTED
            , int   _EXPECTED_CALLED_IS_CONNECTED
            , int   _EXPECTED_CALLED_WRITE
        ) const
        {
            auto    ENDPOINT = static_cast< unsigned char >( 10 );

            auto    usbDeviceManagerImpl = 20;
            auto &  usbDeviceManager = reinterpret_cast< UsbDeviceManager & >( usbDeviceManagerImpl );

            auto    socketImpl = 30;
            auto &  socket = reinterpret_cast< Socket & >( socketImpl );

            auto    buffer = reinterpret_cast< void * >( 40 );
            auto    BUFFER_SIZE = 50;

            returnsBulkTransfer = _RETURNS_BULK_TRANSFER;
            returnsIsConnected = _RETURNS_IS_CONNECTED;
            returnsWrite = _RETURNS_WRITE;

            EXPECT_EQ(
                _EXPECTED
                , repeatFromUsbDevice(
                    ENDPOINT
                    , usbDeviceManager
                    , socket
                    , buffer
                    , BUFFER_SIZE
                )
            );

            EXPECT_EQ( &usbDeviceManager, argsBulkTransfer.usbDeviceManagerPtr );
            EXPECT_EQ( ENDPOINT, argsBulkTransfer.endpoint );
            EXPECT_EQ( buffer, argsBulkTransfer.data );
            EXPECT_EQ( BUFFER_SIZE, argsBulkTransfer.dataSize );

            EXPECT_EQ( _EXPECTED_CALLED_IS_CONNECTED, calledIsConnected );
            if( calledIsConnected > 0 ) {
                EXPECT_EQ( &socket, argsIsConnected.socketPtr );
            }

            EXPECT_EQ( _EXPECTED_CALLED_WRITE, calledWrite );
            if( calledWrite > 0 ) {
                EXPECT_EQ( &socket, argsWrite.socketPtr );
                EXPECT_EQ( buffer, argsWrite.data );
                EXPECT_EQ( _RETURNS_BULK_TRANSFER, argsWrite.dataSize );
            }
        }
    };
}

int UsbDeviceManager::bulkTransfer(
    unsigned char   _ENDPOINT
    , void *        _data
    , int           _DATA_SIZE
)
{
    argsBulkTransfer.usbDeviceManagerPtr = this;
    argsBulkTransfer.endpoint = _ENDPOINT;
    argsBulkTransfer.data = _data;
    argsBulkTransfer.dataSize = _DATA_SIZE;

    return returnsBulkTransfer;
}

int Socket::write(
    const void *    _DATA
    , int           _DATA_SIZE
)
{
    calledWrite++;

    argsWrite.socketPtr = this;
    argsWrite.data = _DATA;
    argsWrite.dataSize = _DATA_SIZE;

    return returnsWrite;
}

bool Socket::isConnected(
)
{
    calledIsConnected++;

    argsIsConnected.socketPtr = this;

    return returnsIsConnected;
}

TEST_F(
    RepeatFromUsbDeviceTest
    , RepeatFromUsbDevice
)
{
    this->test(
        60
        , false
        , 70
        , true
        , 0
        , 1
    );
}

TEST_F(
    RepeatFromUsbDeviceTest
    , Failed_bulkTransfer
)
{
    this->test(
        0
        , true
        , -1
        , true
        , 1
        , 0
    );
}

TEST_F(
    RepeatFromUsbDeviceTest
    , Failed_inConnected
)
{
    this->test(
        0
        , false
        , 60
        , false
        , 1
        , 0
    );
}

//TODO Failed_write
/*
TEST_F(
    RepeatFromUsbDeviceTest
    , Failed_read
)
{
    this->test(
        -1
        , false
        , 0
    );
}
*/

int Socket::read(
    void *
    , int
)
{
    return -1;
}
