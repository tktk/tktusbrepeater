#include "tktusbrepeater/test.h"
#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/socket.h"
#include <cstring>

namespace {
    struct ArgsRead
    {
        Socket *    socketPtr = nullptr;
        void *      data = nullptr;
        int         dataSize = 0;
    };

    struct ArgsBulkTransfer
    {
        UsbDeviceManager *  usbDeviceManagerPtr = nullptr;
        unsigned char       endpoint = 0;
        void *              data = nullptr;
        int                 dataSize = 0;
    };

    auto    argsRead = ArgsRead();
    auto    returnsRead = static_cast< int >( 0 );

    auto    calledBulkTransfer = static_cast< int >( 0 );
    auto    argsBulkTransfer = ArgsBulkTransfer();

    class RepeatFromUsbDeviceTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            argsRead = ArgsRead();
            returnsRead = 0;

            calledBulkTransfer = 0;
            argsBulkTransfer = ArgsBulkTransfer();
        }

    public:
        void test(
            int     _RETURNS_READ
            , bool  _EXPECTED
            , int   _EXPECTED_CALLED_BULK_TRANSFER
        ) const
        {
            auto    ENDPOINT = static_cast< unsigned char >( 10 );

            auto    usbDeviceManagerImpl = 20;
            auto &  usbDeviceManager = reinterpret_cast< UsbDeviceManager & >( usbDeviceManagerImpl );

            auto    socketImpl = 30;
            auto &  socket = reinterpret_cast< Socket & >( socketImpl );

            returnsRead = _RETURNS_READ;

            auto    buffer = reinterpret_cast< void * >( 40 );
            auto    BUFFER_SIZE = 50;

            EXPECT_EQ(
                _EXPECTED
                , repeatToUsbDevice(
                    ENDPOINT
                    , usbDeviceManager
                    , socket
                    , buffer
                    , BUFFER_SIZE
                )
            );

            EXPECT_EQ( &socket, argsRead.socketPtr );
            EXPECT_EQ( buffer, argsRead.data );
            EXPECT_EQ( BUFFER_SIZE, argsRead.dataSize );

            EXPECT_EQ( _EXPECTED_CALLED_BULK_TRANSFER, calledBulkTransfer );
            if( calledBulkTransfer > 0 ) {
                EXPECT_EQ( &usbDeviceManager, argsBulkTransfer.usbDeviceManagerPtr );
                EXPECT_EQ( ENDPOINT, argsBulkTransfer.endpoint );
                EXPECT_EQ( buffer, argsBulkTransfer.data );
                EXPECT_EQ( _RETURNS_READ, argsBulkTransfer.dataSize );
            }
        }
    };
}

int Socket::read(
    void *  _data
    , int   _DATA_SIZE
)
{
    argsRead.socketPtr = this;
    argsRead.data = _data;
    argsRead.dataSize = _DATA_SIZE;

    return returnsRead;
}

int UsbDeviceManager::bulkTransfer(
    unsigned char   _ENDPOINT
    , void *        _data
    , int           _DATA_SIZE
)
{
    calledBulkTransfer++;

    argsBulkTransfer.usbDeviceManagerPtr = this;
    argsBulkTransfer.endpoint = _ENDPOINT;
    argsBulkTransfer.data = _data;
    argsBulkTransfer.dataSize = _DATA_SIZE;

    return 0;
}

//REMOVEME
int Socket::write(
    const void *
    , int
)
{
    return -1;
}

TEST_F(
    RepeatFromUsbDeviceTest
    , RepeatFromUsbDevice
)
{
    this->test(
        50
        , true
        , 1
    );
}

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
