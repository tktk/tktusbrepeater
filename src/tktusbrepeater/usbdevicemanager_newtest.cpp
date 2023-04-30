#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb_mock.h"
#include <functional>

namespace {
    using AssertManager = std::function<
        void (
            const UsbDeviceManager *
        )
    >;

    using AssertUserData = std::function<
        void (
            const void *
            , const UsbDeviceManager *
        )
    >;

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
            int                 _RETURNS_REGISTER_USB_HOTPLUG_CALLBACK
            , AssertManager     _ASSERT_MANAGER
            , AssertUserData    _ASSERT_USER_DATA
        ) const
        {
            auto    dummyContext = reinterpret_cast< UsbContextImpl * >( 10 );
            auto    dummyVendorId = 20;
            auto    dummyProductId = 30;

            returnsRegisterUsbHotplugCallback = _RETURNS_REGISTER_USB_HOTPLUG_CALLBACK;

            auto    usbDeviceManagerUnique = newUsbDeviceManager(
                dummyContext
                , dummyVendorId
                , dummyProductId
            );
            _ASSERT_MANAGER( usbDeviceManagerUnique.get() );

            EXPECT_EQ( 1, calledCountRegisterUsbHotplugCallback );
            EXPECT_EQ( dummyContext, argsRegisterUsbHotplugCallback.context );
            EXPECT_EQ( dummyVendorId, argsRegisterUsbHotplugCallback.vendorId );
            EXPECT_EQ( dummyProductId, argsRegisterUsbHotplugCallback.productId );

            _ASSERT_USER_DATA(
                argsRegisterUsbHotplugCallback.userData
                , usbDeviceManagerUnique.get()
            );
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
        , [](
            const UsbDeviceManager *    _MANAGER_PTR
        )
        {
            EXPECT_NE( nullptr, _MANAGER_PTR );
        }
        , [](
            const void *                _USER_DATA
            , const UsbDeviceManager *  _MANAGER_PTR
        )
        {
            EXPECT_EQ( _MANAGER_PTR, _USER_DATA );
        }
    );
}

TEST_F(
    NewUsbDeviceManagerTest
    , Failed_registerUsbHotplugCallback
)
{
    this->test(
        -1
        , [](
            const UsbDeviceManager *    _MANAGER_PTR
        )
        {
            EXPECT_EQ( nullptr, _MANAGER_PTR );
        }
        , [](
            const void *                _USER_DATA
            , const UsbDeviceManager *
        )
        {
            EXPECT_NE( nullptr, _USER_DATA );
        }
    );
}
