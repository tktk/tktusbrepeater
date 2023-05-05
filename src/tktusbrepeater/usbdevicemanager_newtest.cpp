#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb_mock.h"

namespace {
    struct UsbDeviceManagerImpl
    {
        UsbContextImplUnique    usbContextUnique;

        UsbDeviceImpl * usbDevicePtr;

        std::shared_mutex           usbDeviceMutex;
        UsbDeviceHandleImplUnique   usbDeviceHandleUnique;
    };

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

            returnsInitializeUsbContextImpl = dummyContext;

            auto    usbDeviceManagerUnique = newUsbDeviceManager(
                dummyVendorId
                , dummyProductId
            );

            EXPECT_EQ( 1, calledCountRegisterUsbHotplugCallback );
            EXPECT_EQ( dummyContext, argsRegisterUsbHotplugCallback.context );
            EXPECT_EQ( dummyVendorId, argsRegisterUsbHotplugCallback.vendorId );
            EXPECT_EQ( dummyProductId, argsRegisterUsbHotplugCallback.productId );
            EXPECT_EQ( UsbDeviceManager::callbackUsbHotplug, argsRegisterUsbHotplugCallback.callback );
            EXPECT_EQ( usbDeviceManagerUnique.get(), argsRegisterUsbHotplugCallback.userData );

            auto &  usbDeviceManagerImpl = reinterpret_cast< UsbDeviceManagerImpl & >( *usbDeviceManagerUnique );
            EXPECT_EQ( dummyContext, usbDeviceManagerImpl.usbContextUnique.get() );
            EXPECT_EQ( nullptr, usbDeviceManagerImpl.usbDevicePtr );
            EXPECT_EQ( nullptr, usbDeviceManagerImpl.usbDeviceHandleUnique.get() );
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
