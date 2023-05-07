#include "tktusbrepeater/test.h"
#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/serversocket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class ServerSocket_acceptTest : public ::testing::Test
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
            const auto  SERVER_SOCKET = 10;
            const auto  SOCKET = 20;

            auto    serverSocketImpl = ServerSocketImpl{
                .socket = SERVER_SOCKET,
            };

            returnsAcceptSocketImpl = SOCKET;

            EXPECT_EQ( SOCKET, reinterpret_cast< ServerSocket & >( serverSocketImpl ).accept() );

            EXPECT_EQ( 1, calledCountAcceptSocketImpl );
            EXPECT_EQ( SERVER_SOCKET, argsAcceptSocketImpl.socket );
        }
    };
}

TEST_F(
    ServerSocket_acceptTest
    , Accept
)
{
    this->test();
}
