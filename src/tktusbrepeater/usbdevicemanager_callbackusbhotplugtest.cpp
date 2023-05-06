#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbdevicemanager_test.h"
#include "tktusbrepeater/impl/usb_mock.h"

namespace {
    class UsbDeviceManager_callbackUsbHotplugTest : public ::testing::Test
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
            auto    deviceImpl = reinterpret_cast< UsbDeviceImpl * >( 10 );
            auto    deviceManagerImpl = UsbDeviceManagerImpl();

            auto    deviceHandleImpl = reinterpret_cast< UsbDeviceHandleImpl * >( 20 );

            returnsOpenUsbDeviceImpl = deviceHandleImpl;

            EXPECT_EQ(
                0
                , UsbDeviceManager::callbackUsbHotplug(
                    nullptr
                    , deviceImpl
                    , UsbHotplugEvent::ARRIVED
                    , &deviceManagerImpl
                )
            );

            EXPECT_EQ( deviceImpl, deviceManagerImpl.usbDevicePtr );
            EXPECT_EQ( deviceHandleImpl, deviceManagerImpl.usbDeviceHandleUnique.get() );

            EXPECT_EQ( deviceImpl, argsOpenUsbDeviceImpl.device );
        }
    };
}

TEST_F(
    UsbDeviceManager_callbackUsbHotplugTest
    , ArrivedDevice
)
{
    //TODO
    this->test();
}

//TODO LeftDevice
//TODO ArrivedOtherDevice
//TODO LeftOtherDevice
//TODO Failed_openUsbDeviceImpl
