#include "tktusbrepeater/test.h"
#include "tktusbrepeater/tktusbrepeater.h"
#include "tktusbrepeater/lib/readerwriter_test.h"
#include "tktusbrepeater/lib/impl/socket_mock.h"
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
            int             _SOCKET
            , unsigned char _ENDPOINT
            , bool          _RETURNS_CONNECT_SOCKET_IMPL
            , int           _RETURNS_WRITE_SOCKET_IMPL
            , bool          _EXPECTED_NON_NULL
            , int           _EXPECTED_CALLED_COUNT_CONNECT_SOCKET_IMPL
            , int           _EXPECTED_CALLED_COUNT_WRITE_SOCKET_IMPL
        ) const
        {
            const auto  SOCKET_NAME = "SOCKET_NAME";

            returnsInitializeSocketImpl = _SOCKET;
            returnsConnectSocketImpl = _RETURNS_CONNECT_SOCKET_IMPL;
            returnsWriteSocketImpl = _RETURNS_WRITE_SOCKET_IMPL;

            auto    readerUnique = tktusbrepeater::newReader(
                std::string( SOCKET_NAME )
                , _ENDPOINT
            );

            if( _EXPECTED_NON_NULL == true ) {
                ASSERT_NE( nullptr, readerUnique.get() );

                const auto &    READER_IMPL = reinterpret_cast< const ReaderWriterImpl & >( *readerUnique );
                EXPECT_EQ( _SOCKET, READER_IMPL.socket );
                EXPECT_EQ( &( READER_IMPL.socket ), READER_IMPL.socketCloser.get() );
            } else {
                EXPECT_EQ( nullptr, readerUnique.get() );
            }

            EXPECT_EQ( _EXPECTED_CALLED_COUNT_CONNECT_SOCKET_IMPL, calledCountConnectSocketImpl );
            if( calledCountConnectSocketImpl > 0 ) {
                EXPECT_EQ( _SOCKET, argsConnectSocketImpl.socket );
                EXPECT_STREQ( SOCKET_NAME, argsConnectSocketImpl.pathPtr );
            }

            EXPECT_EQ( _EXPECTED_CALLED_COUNT_WRITE_SOCKET_IMPL, calledCountWriteSocketImpl );
            if( calledCountWriteSocketImpl > 0 ) {
                EXPECT_EQ( _SOCKET, argsWriteSocketImpl.socket );
                ASSERT_EQ( 1, argsWriteSocketImpl.data.size() );
                EXPECT_EQ( _ENDPOINT, argsWriteSocketImpl.data[ 0 ] );
            }
        }
    };
}

TEST_F(
    Reader_newTest
    , New
)
{
    this->test(
        10
        , 0x81
        , true
        , 20
        , true
        , 1
        , 1
    );
}

TEST_F(
    Reader_newTest
    , Failed_illegalEndpoint
)
{
    this->test(
        10
        , 0x1
        , true
        , 20
        , false
        , 0
        , 0
    );
}

TEST_F(
    Reader_newTest
    , Failed_initializeSocketImpl
)
{
    this->test(
        -1
        , 0x81
        , true
        , 20
        , false
        , 0
        , 0
    );
}

TEST_F(
    Reader_newTest
    , Failed_connectSocketImpl
)
{
    this->test(
        10
        , 0x81
        , false
        , 20
        , false
        , 1
        , 0
    );
}

TEST_F(
    Reader_newTest
    , Failed_writeSocketImpl
)
{
    this->test(
        10
        , 0x81
        , true
        , -1
        , false
        , 1
        , 1
    );
}
