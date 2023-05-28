#include "tktusbrepeater/test.h"
#include "tktusbrepeater/tktusbrepeater.h"
#include "tktusbrepeater/lib/readerwriter_test.h"
#include "tktusbrepeater/lib/impl/socket_mock.h"

namespace {
    class Reader_readTest : public ::testing::Test
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
            const auto  BUFFER = reinterpret_cast< void * >( 20 );
            const auto  BUFFER_SIZE = 30;
            const auto  READ_SIZE = 40;

            returnsReadSocketImpl = READ_SIZE;

            auto    readerWriterImpl = ReaderWriterImpl{
                SOCKET,
            };

            EXPECT_EQ(
                READ_SIZE
                , reinterpret_cast< tktusbrepeater::Reader & >( readerWriterImpl ).read(
                    BUFFER
                    , BUFFER_SIZE
                )
            );

            EXPECT_EQ( SOCKET, argsReadSocketImpl.socket );
            EXPECT_EQ( BUFFER, argsReadSocketImpl.data );
            EXPECT_EQ( BUFFER_SIZE, argsReadSocketImpl.dataSize );
        }
    };
}

TEST_F(
    Reader_readTest
    , Read
)
{
    this->test();
}
