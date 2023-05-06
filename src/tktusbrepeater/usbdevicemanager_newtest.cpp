#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbdevicemanager_test.h"
#include "tktusbrepeater/impl/usb_mock.h"

namespace {
    class UsbDeviceManager_newTest : public ::testing::Test
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

            EXPECT_EQ( 1, calledCountRegisterCallbackUsbHotplugImpl );
            EXPECT_EQ( dummyContext, argsRegisterCallbackUsbHotplugImpl.context );
            EXPECT_EQ( dummyVendorId, argsRegisterCallbackUsbHotplugImpl.vendorId );
            EXPECT_EQ( dummyProductId, argsRegisterCallbackUsbHotplugImpl.productId );
            EXPECT_EQ( UsbDeviceManager::callbackUsbHotplug, argsRegisterCallbackUsbHotplugImpl.callback );
            EXPECT_EQ( usbDeviceManagerUnique.get(), argsRegisterCallbackUsbHotplugImpl.userData );

            auto &  usbDeviceManagerImpl = reinterpret_cast< UsbDeviceManagerImpl & >( *usbDeviceManagerUnique );
            EXPECT_EQ( dummyContext, usbDeviceManagerImpl.usbContextUnique.get() );
            EXPECT_EQ( nullptr, usbDeviceManagerImpl.usbDevicePtr );
            EXPECT_EQ( nullptr, usbDeviceManagerImpl.usbDeviceHandleUnique.get() );
        }
    };
}

TEST_F(
    UsbDeviceManager_newTest
    , New
)
{
    this->test();
}
