#include "tktusbrepeater/test.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/socket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class Socket_readTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeSocketMock();
        }

    public:
        void test(
        ) const
        {
            const auto  SOCKET = 10;
            const auto  READ_SIZE = 20;
            auto        data = reinterpret_cast< void * >( 30 );
            const auto  DATA_SIZE = 40;

            auto    socketImpl = SocketImpl{
                .socket = SOCKET,
            };

            returnsReadSocketImpl = READ_SIZE;

            EXPECT_EQ(
                READ_SIZE
                , reinterpret_cast< Socket & >( socketImpl ).read(
                    data
                    , DATA_SIZE
                )
            );

            EXPECT_EQ( 1, calledCountReadSocketImpl );
            EXPECT_EQ( SOCKET, argsReadSocketImpl.socket );
            EXPECT_EQ( data, argsReadSocketImpl.data );
            EXPECT_EQ( DATA_SIZE, argsReadSocketImpl.dataSize );
        }
    };
}

TEST_F(
    Socket_readTest
    , Read
)
{
    this->test();
}
