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
        void test(
        ) const
        {
            auto    deviceHandleImpl = reinterpret_cast< UsbDeviceHandleImpl * >( 10 );

            const auto  ENDPOINT = 20;
            const auto  DATA = reinterpret_cast< void * >( 30 );
            const auto  DATA_SIZE = 40;

            const auto  TRANSFERRED = 50;

            auto    usbDeviceManagerImpl = UsbDeviceManagerImpl{
                .usbDeviceHandleUnique = UsbDeviceHandleImplUnique( deviceHandleImpl ),
            };

            returnsBulkTransferUsbImpl = TRANSFERRED;

            EXPECT_EQ(
                TRANSFERRED
                , reinterpret_cast< UsbDeviceManager & >( usbDeviceManagerImpl ).bulkTransfer(
                    ENDPOINT
                    , DATA
                    , DATA_SIZE
                )
            );

            EXPECT_EQ( 1, calledCountBulkTransferUsbImpl );
            EXPECT_EQ( deviceHandleImpl, argsBulkTransferUsbImpl.deviceHandle );
            EXPECT_EQ( ENDPOINT, argsBulkTransferUsbImpl.endpoint );
            EXPECT_EQ( DATA, argsBulkTransferUsbImpl.data );
            EXPECT_EQ( DATA_SIZE, argsBulkTransferUsbImpl.dataSize );
        }
    };
}

TEST_F(
    UsbDeviceManager_bulkTransferTest
    , BulkTransfer
)
{
    this->test();
}
