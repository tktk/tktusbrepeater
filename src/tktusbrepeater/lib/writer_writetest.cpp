#include "tktusbrepeater/test.h"
#include "tktusbrepeater/tktusbrepeater.h"
#include "tktusbrepeater/lib/readerwriter_test.h"
#include "tktusbrepeater/lib/impl/socket_mock.h"

namespace {
    class Writer_writeTest : public ::testing::Test
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
            const auto  DATA = std::string( "DATA" );
            const auto  WRITE_SIZE = 20;

            returnsWriteSocketImpl = WRITE_SIZE;

            auto    readerWriterImpl = ReaderWriterImpl{
                SOCKET,
            };

            EXPECT_EQ(
                WRITE_SIZE
                , reinterpret_cast< tktusbrepeater::Writer & >( readerWriterImpl ).write(
                    DATA.c_str()
                    , DATA.size()
                )
            );

            EXPECT_EQ( SOCKET, argsWriteSocketImpl.socket );
            EXPECT_EQ(
                std::vector< unsigned char >(
                    {
                        'D',
                        'A',
                        'T',
                        'A',
                    }
                )
                , argsWriteSocketImpl.data
            );
        }
    };
}

TEST_F(
    Writer_writeTest
    , Write
)
{
    this->test();
}
