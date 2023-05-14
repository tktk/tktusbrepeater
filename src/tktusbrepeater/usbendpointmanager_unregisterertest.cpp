#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbendpointmanager_test.h"
#include <vector>

namespace {
    class UsbEndpointManager_UnregistererTest : public ::testing::Test
    {
    public:
        void test(
            const std::vector< unsigned char > &    _ENDPOINTS
            , unsigned char                         _ENDPOINT
            , const std::vector< unsigned char > &  _EXPECTED_ENDPOINTS
        ) const
        {
            auto    usbEndpointManager = UsbEndpointManager();

            auto &  usbEndpointManagerImpl = reinterpret_cast< UsbEndpointManagerImpl & >( usbEndpointManager );
            usbEndpointManagerImpl.endpoints = _ENDPOINTS;

            auto    unregistererUnique = UsbEndpointManager::UnregistererUnique(
                new UsbEndpointManager::Unregisterer(
                    usbEndpointManager
                    , _ENDPOINT
                )
            );
            unregistererUnique.reset();

            EXPECT_EQ( _EXPECTED_ENDPOINTS, usbEndpointManagerImpl.endpoints );
        }
    };
}

TEST_F(
    UsbEndpointManager_UnregistererTest
    , Unregister
)
{
    this->test(
        {
            10,
            20,
            30,
        }
        , 20
        , {
            10,
            30,
        }
    );
}

TEST_F(
    UsbEndpointManager_UnregistererTest
    , NotExists
)
{
    this->test(
        {
            10,
            20,
            30,
        }
        , 25
        , {
            10,
            20,
            30,
        }
    );
}
