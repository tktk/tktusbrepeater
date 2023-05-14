#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbendpointmanager_test.h"
#include <vector>

namespace {
    class UsbEndpointManager_reginterEndpointTest : public ::testing::Test
    {
    public:
        void test(
        ) const
        {
            auto    usbEndpointManager = UsbEndpointManager();

            auto &  usbEndpointManagerImpl = reinterpret_cast< UsbEndpointManagerImpl & >( usbEndpointManager );
            usbEndpointManagerImpl.endpoints = {
                10,
                30,
            };

            const auto  ENDPOINT = 20;

            auto    unregistererUnique = usbEndpointManager.registerEndpoint( ENDPOINT );
            ASSERT_NE( nullptr, unregistererUnique.get() );

            EXPECT_EQ( &usbEndpointManager, &( unregistererUnique->endpointManager ) );
            EXPECT_EQ( ENDPOINT, unregistererUnique->ENDPOINT );
            EXPECT_EQ( unregistererUnique.get(), unregistererUnique->unregistererUnique.get() );

            EXPECT_EQ(
                std::vector< unsigned char >(
                    {
                        10,
                        20,
                        30,
                    }
                )
                , usbEndpointManagerImpl.endpoints
            );
        }
    };
}

TEST_F(
    UsbEndpointManager_reginterEndpointTest
    , NotExists
)
{
    this->test();
}

//TODO AlreadyExists
