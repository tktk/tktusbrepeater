#include "tktusbrepeater/test.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbdevicemanager_test.h"
#include "tktusbrepeater/impl/usb_mock.h"

namespace {
    class UsbDeviceManager_bulkTransferTest : public ::testing::Test
    {
    protected:
        virtual void SetUp(
        ) override
        {
            initializeUsbMock();
        }

    public:
        UsbDeviceHandleImpl *   deviceHandleImpl = reinterpret_cast< UsbDeviceHandleImpl * >( 10 );

        const int   TRANSFERRED = 20;

        void test(
            UsbDeviceHandleImpl *   _deviceHandleImpl
            , int                   _EXPECTED
            , int                   _EXPECTED_CALLED_COUNT_BULK_TRANSFER_USB_IMPL
            , UsbDeviceHandleImpl * _EXPECTED_ARG_BULK_TRANSFER_USB_IMPL_DEVICE_HANDLE_IMPL
        ) const
        {
            const auto  ENDPOINT = 30;
            const auto  DATA = reinterpret_cast< void * >( 40 );
            const auto  DATA_SIZE = 50;

            auto    usbDeviceManagerImpl = UsbDeviceManagerImpl{
                .usbDeviceHandleUnique = UsbDeviceHandleImplUnique( _deviceHandleImpl ),
            };

            returnsBulkTransferUsbImpl = this->TRANSFERRED;

            EXPECT_EQ(
                _EXPECTED
                , reinterpret_cast< UsbDeviceManager & >( usbDeviceManagerImpl ).bulkTransfer(
                    ENDPOINT
                    , DATA
                    , DATA_SIZE
                )
            );

            EXPECT_EQ( _EXPECTED_CALLED_COUNT_BULK_TRANSFER_USB_IMPL, calledCountBulkTransferUsbImpl );
            if( calledCountBulkTransferUsbImpl > 0 ) {
                EXPECT_EQ( _EXPECTED_ARG_BULK_TRANSFER_USB_IMPL_DEVICE_HANDLE_IMPL, argsBulkTransferUsbImpl.deviceHandle );
                EXPECT_EQ( ENDPOINT, argsBulkTransferUsbImpl.endpoint );
                EXPECT_EQ( DATA, argsBulkTransferUsbImpl.data );
                EXPECT_EQ( DATA_SIZE, argsBulkTransferUsbImpl.dataSize );
            }
        }
    };
}

TEST_F(
    UsbDeviceManager_bulkTransferTest
    , BulkTransfer
)
{
    this->test(
        this->deviceHandleImpl
        , this->TRANSFERRED
        , 1
        , this->deviceHandleImpl
    );
}

TEST_F(
    UsbDeviceManager_bulkTransferTest
    , NotConnected
)
{
    this->test(
        nullptr
        , 0
        , 0
        , nullptr
    );
}
