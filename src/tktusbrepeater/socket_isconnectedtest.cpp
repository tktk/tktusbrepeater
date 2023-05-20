#include "tktusbrepeater/test.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/socket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class Socket_isConnectedTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeSocketMock();
        }

    public:
        void test(
            bool    _RETURNS_IS_CONNECTED_SOCKET_IMPL
            , bool  _EXPECTED
        ) const
        {
            const auto  SOCKET = 10;

            auto    socketImpl = SocketImpl{
                .socket = SOCKET,
            };

            returnsIsConnectedSocketImpl = _RETURNS_IS_CONNECTED_SOCKET_IMPL;

            EXPECT_EQ( _EXPECTED, reinterpret_cast< Socket & >( socketImpl ).isConnected() );

            EXPECT_EQ( 1, calledCountIsConnectedSocketImpl );
            EXPECT_EQ( SOCKET, argsIsConnectedSocketImpl.socket );
        }
    };
}

TEST_F(
    Socket_isConnectedTest
    , IsConnected_connected
)
{
    this->test(
        true
        , true
    );
}

/*
TEST_F(
    Socket_isConnectedTest
    , IsConnected_disconnected
)
{
    this->test(
        true
        , true
    );
}
*/
