#include "tktusbrepeater/test.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/socket_test.h"

namespace {
    class Socket_newTest : public ::testing::Test
    {
    public:
        void test(
        ) const
        {
            const auto  SOCKET = 10;

            auto    socketUnique = newSocket( SOCKET );
            ASSERT_NE( nullptr, socketUnique.get() );

            auto &  socketImpl = reinterpret_cast< SocketImpl & >( *socketUnique );
            EXPECT_EQ( SOCKET, socketImpl.socket );
            EXPECT_EQ( &( socketImpl.socket ), socketImpl.socketCloser.get() );
        }
    };
}

TEST_F(
    Socket_newTest
    , New
)
{
    this->test();
}
