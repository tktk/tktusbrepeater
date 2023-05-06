#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbdevicemanager_test.h"
#include "tktusbrepeater/impl/usb_mock.h"

namespace {
    class UsbDeviceManager_handleEventsTest : public ::testing::Test
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
            auto    contextImpl = reinterpret_cast< UsbContextImpl * >( 10 );

            auto    usbDeviceManagerImpl = UsbDeviceManagerImpl{
                .usbContextUnique = UsbContextImplUnique( contextImpl ),
            };

            reinterpret_cast< UsbDeviceManager & >( usbDeviceManagerImpl ).handleEvents();

            EXPECT_EQ( 1, calledCountHandleUsbEventsImpl );
            EXPECT_EQ( contextImpl, argsHandleUsbEventsImpl.context );
        }
    };
}

TEST_F(
    UsbDeviceManager_handleEventsTest
    , HandleEvents
)
{
    this->test();
}
