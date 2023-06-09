#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbendpointmanager_test.h"
#include <vector>

namespace {
    class UsbEndpointManager_registerEndpointTest : public ::testing::Test
    {
    public:
        void test(
            const std::vector< unsigned char > &    _ENDPOINTS
            , unsigned char                         _ENDPOINT
            , bool                                  _EXPECTED_IS_NOT_NULL
            , const std::vector< unsigned char > &  _EXPECTED_ENDPOINTS
        ) const
        {
            auto    usbEndpointManager = UsbEndpointManager();

            auto &  usbEndpointManagerImpl = reinterpret_cast< UsbEndpointManagerImpl & >( usbEndpointManager );
            usbEndpointManagerImpl.endpoints = _ENDPOINTS;

            auto    unregistererUnique = usbEndpointManager.registerEndpoint( _ENDPOINT );
            if( _EXPECTED_IS_NOT_NULL == true ) {
                ASSERT_NE( nullptr, unregistererUnique.get() );

                EXPECT_EQ( &usbEndpointManager, &( unregistererUnique->endpointManager ) );
                EXPECT_EQ( _ENDPOINT, unregistererUnique->ENDPOINT );
                EXPECT_EQ( unregistererUnique.get(), unregistererUnique->unregistererUnique.get() );
            } else {
                EXPECT_EQ( nullptr, unregistererUnique.get() );
            }

            EXPECT_EQ( _EXPECTED_ENDPOINTS, usbEndpointManagerImpl.endpoints );
        }
    };
}

TEST_F(
    UsbEndpointManager_registerEndpointTest
    , NotExists
)
{
    this->test(
        {
            10,
            30,
        }
        , 20
        , true
        , {
            10,
            20,
            30,
        }
    );
}

TEST_F(
    UsbEndpointManager_registerEndpointTest
    , AlreadyExists
)
{
    this->test(
        {
            10,
            20,
            30,
        }
        , 20
        , false
        , {
            10,
            20,
            30,
        }
    );
}

TEST_F(
    UsbEndpointManager_registerEndpointTest
    , FirstRegister
)
{
    this->test(
        {
        }
        , 10
        , true
        , {
            10,
        }
    );
}
