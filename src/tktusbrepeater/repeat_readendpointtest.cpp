#include "tktusbrepeater/test.h"
#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/socket.h"
#include <cstring>

namespace {
    struct ArgsRead
    {
        Socket *    socketPtr = nullptr;
        int         dataSize = 0;
    };

    auto    readData = static_cast< unsigned char >( 0 );

    auto    argsRead = ArgsRead();
    auto    returnsRead = static_cast< int >( 0 );

    class ReadEndpointTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            readData = 0;

            argsRead = ArgsRead();
            returnsRead = 0;
        }

    public:
        void test(
            unsigned char   _ENDPOINT
            , int           _RETURNS_READ
            , bool          _EXPECTED
            , unsigned char _EXPECTED_ENDPOINT
        ) const
        {
            auto    endpoint = static_cast< unsigned char >( 0 );
            auto    socketImpl = 10;
            auto &  socket = reinterpret_cast< Socket & >( socketImpl );

            readData = _ENDPOINT;
            returnsRead = _RETURNS_READ;

            EXPECT_EQ(
                _EXPECTED
                , readEndpoint(
                    endpoint
                    , socket
                )
            );

            EXPECT_EQ( _EXPECTED_ENDPOINT, endpoint );
            EXPECT_EQ( &socket, argsRead.socketPtr );
            EXPECT_EQ( 1, argsRead.dataSize );
        }
    };
}

int Socket::read(
    void *  _data
    , int   _DATA_SIZE
)
{
    argsRead.socketPtr = this;
    argsRead.dataSize = _DATA_SIZE;

    if( returnsRead >= 0 ) {
        std::memcpy(
            _data
            , &readData
            , sizeof( readData )
        );
    }

    return returnsRead;
}

TEST_F(
    ReadEndpointTest
    , ReadEndpoint
)
{
    this->test(
        20
        , 1
        , true
        , 20
    );
}

TEST_F(
    ReadEndpointTest
    , Failed_read
)
{
    this->test(
        20
        , -1
        , false
        , 0
    );
}

int UsbDeviceManager::bulkTransfer(
    unsigned char
    , void *
    , int
)
{
    return -1;
}

int Socket::write(
    const void *
    , int
)
{
    return -1;
}

bool Socket::isConnected(
)
{
    return false;
}
