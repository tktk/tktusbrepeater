#include "tktusbrepeater/test.h"
#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/socket.h"
#include <cstring>

namespace {
    struct ArgsRead
    {
        int dataSize = 0;
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
        ) const
        {
            auto    endpoint = static_cast< unsigned char >( 0 );
            auto    socketImpl = 10;
            auto &  socket = reinterpret_cast< Socket & >( socketImpl );

            const auto  ENDPOINT = static_cast< unsigned char >( 20 );

            readData = ENDPOINT;
            returnsRead = 1;

            EXPECT_EQ(
                true
                , readEndpoint(
                    endpoint
                    , socket
                )
            );

            EXPECT_EQ( ENDPOINT, endpoint );
            EXPECT_EQ( 1, argsRead.dataSize );
        }
    };
}

int Socket::read(
    void *  _data
    , int   _DATA_SIZE
)
{
    argsRead.dataSize = _DATA_SIZE;

    std::memcpy(
        _data
        , &readData
        , sizeof( readData )
    );

    return returnsRead;
}

TEST_F(
    ReadEndpointTest
    , ReadEndpoint
)
{
    this->test();
}

//TODO
/*
TEST_F(
    ReadEndpointTest
    , Falied_read
)
{
    this->test(
        {
            10,
            20,
            30,
        }
        , 25
        , {
            10,
            20,
            30,
        }
    );
}
*/
