#include "tktusbrepeater/test.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/socket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class Socket_writeTest : public ::testing::Test
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
            const auto  WRITE_SIZE = 20;
            const auto  DATA = reinterpret_cast< const void * >( 30 );
            const auto  DATA_SIZE = 40;

            auto    socketImpl = SocketImpl{
                .socket = SOCKET,
            };

            returnsWriteSocketImpl = WRITE_SIZE;

            EXPECT_EQ(
                WRITE_SIZE
                , reinterpret_cast< Socket & >( socketImpl ).write(
                    DATA
                    , DATA_SIZE
                )
            );

            EXPECT_EQ( 1, calledCountWriteSocketImpl );
            EXPECT_EQ( SOCKET, argsWriteSocketImpl.socket );
            EXPECT_EQ( DATA, argsWriteSocketImpl.data );
            EXPECT_EQ( DATA_SIZE, argsWriteSocketImpl.dataSize );
        }
    };
}

TEST_F(
    Socket_writeTest
    , Write
)
{
    this->test();
}
