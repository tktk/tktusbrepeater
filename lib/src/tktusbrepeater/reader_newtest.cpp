#include "tktusbrepeater/test.h"
#include "tktusbrepeater/tktusbrepeater.h"
#include "tktusbrepeater/readerwriter_test.h"
#include "tktusbrepeater/impl/socket_mock.h"
#include <string>

namespace {
    class Reader_newTest : public ::testing::Test
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
            const auto  SOCKET_NAME = std::string( "SOCKET_NAME" );
            const auto  ENDPOINT = static_cast< unsigned char >( 10 );

            const auto  SOCKET = 20;

            returnsInitializeSocketImpl = SOCKET;

            auto    readerUnique = tktusbrepeater::newReader(
                SOCKET_NAME
                , ENDPOINT
            );
            ASSERT_NE( nullptr, readerUnique.get() );

            const auto &    READER_IMPL = reinterpret_cast< const ReaderWriterImpl & >( *readerUnique );
            EXPECT_EQ( SOCKET, READER_IMPL.socket );

            EXPECT_EQ( 1, calledCountConnectSocketImpl );
            if( calledCountConnectSocketImpl > 0 ) {
                EXPECT_EQ( SOCKET, argsConnectSocketImpl.socket );
                EXPECT_EQ( &SOCKET_NAME, argsConnectSocketImpl.pathPtr );
            }

            EXPECT_EQ( 1, calledCountWriteSocketImpl );
            if( calledCountWriteSocketImpl > 0 ) {
                EXPECT_EQ( SOCKET, argsWriteSocketImpl.socket );
                ASSERT_EQ( 1, argsWriteSocketImpl.data.size() );
                ASSERT_EQ( ENDPOINT, argsWriteSocketImpl.data[ 0 ] );
            }
        }
    };
}

TEST_F(
    Reader_newTest
    , New
)
{
    this->test();
}

//TODO Failed_initializeSocketImpl
//TODO Failed_connectSocketImpl
//TODO Failed_writeSocketImpl
