#include "tktusbrepeater/test.h"
#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/serversocket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"

namespace {
    class ServerSocket_pollInTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeSocketMock();
        }

    public:
        void test(
            bool    _RETURNS_POLL_IN_SOCKET_IMPL
            , bool  _EXPECTED
        ) const
        {
            const auto  SOCKET = 10;
            const auto  TIMEOUT = 20;

            auto    serverSocketImpl = ServerSocketImpl{
                .socket = SOCKET,
            };

            returnsPollInSocketImpl = _RETURNS_POLL_IN_SOCKET_IMPL;

            EXPECT_EQ( _EXPECTED, reinterpret_cast< ServerSocket & >( serverSocketImpl ).pollIn( TIMEOUT ) );

            EXPECT_EQ( 1, calledCountPollInSocketImpl );
            EXPECT_EQ( SOCKET, argsPollInSocketImpl.socket );
            EXPECT_EQ( TIMEOUT, argsPollInSocketImpl.timeout );
        }
    };
}

TEST_F(
    ServerSocket_pollInTest
    , PollIn_existsReadData
)
{
    this->test(
        true
        , true
    );
}

TEST_F(
    ServerSocket_pollInTest
    , PollIn_notExistsReadData
)
{
    this->test(
        false
        , false
    );
}
