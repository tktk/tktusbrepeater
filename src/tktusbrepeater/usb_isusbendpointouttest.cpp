#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usb.h"

namespace {
    class IsUsbEndpointOutTest : public ::testing::Test
    {
    public:
        void test(
            unsigned char   _ENDPOINT
            , bool          _EXPECTED
        ) const
        {
            EXPECT_EQ( _EXPECTED, isUsbEndpointOut( _ENDPOINT ) );
        }
    };
}

TEST_F(
    IsUsbEndpointOutTest
    , EndpointOut
)
{
    this->test(
        0x01
        , true
    );
}

//TODO EndpointIn
