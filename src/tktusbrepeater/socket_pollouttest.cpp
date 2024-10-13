#include "tktusbrepeater/test.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/socket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class Socket_pollOutTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeSocketMock();
        }

    public:
        void test(
            bool    _RETURNS_POLL_OUT_SOCKET_IMPL
            , bool  _EXPECTED
        ) const
        {
            const auto  SOCKET = 10;
            const auto  TIMEOUT = 20;

            auto    socketImpl = SocketImpl{
                .socket = SOCKET,
            };

            returnsPollOutSocketImpl = _RETURNS_POLL_OUT_SOCKET_IMPL;

            EXPECT_EQ( _EXPECTED, reinterpret_cast< Socket & >( socketImpl ).pollOut( TIMEOUT ) );

            EXPECT_EQ( 1, calledCountPollOutSocketImpl );
            EXPECT_EQ( SOCKET, argsPollOutSocketImpl.socket );
            EXPECT_EQ( TIMEOUT, argsPollOutSocketImpl.timeout );
        }
    };
}

TEST_F(
    Socket_pollOutTest
    , PollOut_availableWrite
)
{
    this->test(
        true
        , true
    );
}

TEST_F(
    Socket_pollOutTest
    , PollOut_unavailableWrite
)
{
    this->test(
        false
        , false
    );
}
