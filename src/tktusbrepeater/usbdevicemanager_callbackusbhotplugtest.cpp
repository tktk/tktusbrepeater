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
        UsbDeviceImpl *         deviceImpl = reinterpret_cast< UsbDeviceImpl * >( 10 );
        UsbDeviceHandleImpl *   deviceHandleImpl = reinterpret_cast< UsbDeviceHandleImpl * >( 20 );

        void test(
            UsbHotplugEvent                 _EVENT
            , UsbDeviceImpl *               _usbDevicePtr
            , UsbDeviceHandleImpl *         _usbDeviceHandleUniquePtr
            , const UsbDeviceImpl *         _EXPECTED_USB_DEVICE_PTR
            , const UsbDeviceHandleImpl *   _EXPECTED_USB_DEVICE_HANDLE_UNIQUE_PTR
            , const int                     _EXPECTED_CALLED_COUNT_OPEN_USB_DEVICE_IMPL
            , const UsbDeviceImpl *         _EXPECTED_ARG_OPEN_USB_DEVICE_IMPL_DEVICE
        ) const
        {
            auto    deviceManagerImpl = UsbDeviceManagerImpl{
                .usbDevicePtr = _usbDevicePtr,
                .usbDeviceHandleUnique = UsbDeviceHandleImplUnique( _usbDeviceHandleUniquePtr ),
            };

            returnsOpenUsbDeviceImpl = this->deviceHandleImpl;

            EXPECT_EQ(
                0
                , UsbDeviceManager::callbackUsbHotplug(
                    nullptr
                    , this->deviceImpl
                    , _EVENT
                    , &deviceManagerImpl
                )
            );

            EXPECT_EQ( _EXPECTED_USB_DEVICE_PTR, deviceManagerImpl.usbDevicePtr );
            EXPECT_EQ( _EXPECTED_USB_DEVICE_HANDLE_UNIQUE_PTR, deviceManagerImpl.usbDeviceHandleUnique.get() );

            EXPECT_EQ( _EXPECTED_CALLED_COUNT_OPEN_USB_DEVICE_IMPL, calledCountOpenUsbDeviceImpl );
            if( calledCountOpenUsbDeviceImpl > 0 ) {
                EXPECT_EQ( _EXPECTED_ARG_OPEN_USB_DEVICE_IMPL_DEVICE, argsOpenUsbDeviceImpl.device );
            }
        }
    };
}

TEST_F(
    UsbDeviceManager_callbackUsbHotplugTest
    , ArrivedDevice
)
{
    this->test(
        UsbHotplugEvent::ARRIVED
        , nullptr
        , nullptr
        , this->deviceImpl
        , this->deviceHandleImpl
        , 1
        , this->deviceImpl
    );
}

TEST_F(
    UsbDeviceManager_callbackUsbHotplugTest
    , LeftDevice
)
{
    this->test(
        UsbHotplugEvent::LEFT
        , this->deviceImpl
        , this->deviceHandleImpl
        , nullptr
        , nullptr
        , 0
        , nullptr
    );
}

//TODO ArrivedOtherDevice
//TODO LeftOtherDevice
//TODO Failed_openUsbDeviceImpl
