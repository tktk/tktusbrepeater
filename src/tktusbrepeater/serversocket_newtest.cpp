#include "tktusbrepeater/test.h"
#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/serversocket_test.h"
#include "tktusbrepeater/impl/socket_mock.h"
#include <string>

namespace {
    class ServerSocket_newTest : public ::testing::Test
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
            const auto  PATH = std::string( "PATH" );

            const auto  SOCKET = 10;

            returnsInitializeSocketImpl = SOCKET;

            auto    serverSocketUnique = newServerSocket( PATH );
            ASSERT_NE( nullptr, serverSocketUnique.get() );

            auto &  serverSocketImpl = reinterpret_cast< ServerSocketImpl & >( *serverSocketUnique );
            EXPECT_EQ( SOCKET, serverSocketImpl.socket );
            EXPECT_EQ( &( serverSocketImpl.socket ), serverSocketImpl.socketCloser.get() );

            EXPECT_EQ( 1, calledCountBindSocketImpl );
            EXPECT_EQ( SOCKET, argsBindSocketImpl.socket );
            EXPECT_EQ( &PATH, argsBindSocketImpl.pathPtr );

            EXPECT_EQ( 1, calledCountListenSocketImpl );
            EXPECT_EQ( SOCKET, argsListenSocketImpl.socket );
        }
    };
}

TEST_F(
    ServerSocket_newTest
    , New
)
{
    this->test();
}
