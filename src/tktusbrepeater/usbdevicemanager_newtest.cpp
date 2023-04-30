#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb_mock.h"
#include <stdexcept>

namespace {
    class NewUsbDeviceManagerTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeUsbMock();
        }

    public:
        void test(
            int     _RETURNS_REGISTER_USB_HOTPLUG_CALLBACK
            , bool  _EXPECTED_THROW_EXCEPTION
        ) const
        {
            auto    dummyContext = reinterpret_cast< UsbContextImpl * >( 10 );
            auto    dummyVendorId = 20;
            auto    dummyProductId = 30;

            returnsRegisterUsbHotplugCallback = _RETURNS_REGISTER_USB_HOTPLUG_CALLBACK;

            auto    usbDeviceManagerUnique = UsbDeviceManagerUnique();

            try {
                usbDeviceManagerUnique = newUsbDeviceManager(
                    dummyContext
                    , dummyVendorId
                    , dummyProductId
                );

                ASSERT_FALSE( _EXPECTED_THROW_EXCEPTION );

                EXPECT_EQ( 1, calledCountRegisterUsbHotplugCallback );
                EXPECT_EQ( dummyContext, argsRegisterUsbHotplugCallback.context );
                EXPECT_EQ( dummyVendorId, argsRegisterUsbHotplugCallback.vendorId );
                EXPECT_EQ( dummyProductId, argsRegisterUsbHotplugCallback.productId );
                EXPECT_EQ( usbDeviceManagerUnique.get(), argsRegisterUsbHotplugCallback.userData );
            } catch( const std::runtime_error & ) {}
        }
    };
}

TEST_F(
    NewUsbDeviceManagerTest
    , New
)
{
    this->test(
        0
        , false
    );
}

TEST_F(
    NewUsbDeviceManagerTest
    , Failed_registerUsbHotplugCallback
)
{
    this->test(
        -1
        , true
    );
}
