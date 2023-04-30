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

            auto    usbDeviceManagerUnique = UsbDeviceManagerUnique();

            usbDeviceManagerUnique = newUsbDeviceManager(
                dummyContext
                , dummyVendorId
                , dummyProductId
            );

            EXPECT_EQ( 1, calledCountRegisterUsbHotplugCallback );
            EXPECT_EQ( dummyContext, argsRegisterUsbHotplugCallback.context );
            EXPECT_EQ( dummyVendorId, argsRegisterUsbHotplugCallback.vendorId );
            EXPECT_EQ( dummyProductId, argsRegisterUsbHotplugCallback.productId );
            EXPECT_EQ( usbDeviceManagerUnique.get(), argsRegisterUsbHotplugCallback.userData );
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
