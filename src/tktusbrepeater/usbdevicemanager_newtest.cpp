#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb_mock.h"

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
        ) const
        {
            auto    dummyContext = reinterpret_cast< UsbContextImpl * >( 10 );
            auto    dummyVendorId = 20;
            auto    dummyProductId = 30;

            auto    usbDeviceManagerUnique = newUsbDeviceManager(
                dummyContext
                , dummyVendorId
                , dummyProductId
            );
            EXPECT_NE( nullptr, usbDeviceManagerUnique.get() );

            EXPECT_EQ( 1, registerUsbHotplugCallbackCalledCount );
            EXPECT_EQ( dummyContext, registerUsbHotplugCallbackArgs.context );
            EXPECT_EQ( dummyVendorId, registerUsbHotplugCallbackArgs.vendorId );
            EXPECT_EQ( dummyProductId, registerUsbHotplugCallbackArgs.productId );
            EXPECT_EQ( usbDeviceManagerUnique.get(), registerUsbHotplugCallbackArgs.userData );
        }
    };
}

TEST_F(
    NewUsbDeviceManagerTest
    , New
)
{
    this->test();
}
