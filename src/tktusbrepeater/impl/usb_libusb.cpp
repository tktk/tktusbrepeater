#include "tktusbrepeater/impl/usb.h"
#include <libusb-1.0/libusb.h>
#include <sstream>
#include <stdexcept>

namespace {
    enum {
        TIMEOUT_BULK_TRANSFER = 500,
    };
}

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *   _deviceHandleImpl
)
{
    libusb_close( reinterpret_cast< libusb_device_handle * >( _deviceHandleImpl ) );
}

UsbDeviceHandleImplUnique openUsbDeviceImpl(
    UsbDeviceImpl * _deviceImpl
)
{
    auto    deviceHandleImpl = static_cast< libusb_device_handle * >( nullptr );

    if( libusb_open(
        reinterpret_cast< libusb_device * >( _deviceImpl )
        , &deviceHandleImpl
    ) != 0 ) {
        return nullptr;
    }

    return UsbDeviceHandleImplUnique( reinterpret_cast< UsbDeviceHandleImpl * >( deviceHandleImpl ) );
}

void exitUsbContextImpl(
    UsbContextImpl *    _contextImpl
)
{
    libusb_exit( reinterpret_cast< libusb_context * >( _contextImpl ) );
}

UsbContextImplUnique initializeUsbContextImpl(
)
{
    auto    contextImpl = static_cast< libusb_context * >( nullptr );

    const auto  ERROR_CODE = libusb_init( &contextImpl );
    if( ERROR_CODE != 0 ) {
        auto    stringStream = std::stringstream();

        stringStream << "libusb_init()が失敗 : " << ERROR_CODE;

        throw std::runtime_error( stringStream.str() );
    }

    return UsbContextImplUnique( reinterpret_cast< UsbContextImpl * >( contextImpl ) );
}

void registerCallbackUsbHotplugImpl(
    UsbContextImpl *            _contextImpl
    , int                       _VENDOR_ID
    , int                       _PRODUCT_ID
    , CallbackUsbHotplugImpl    _callbackUsbHotplugImpl
    , void *                    _userData
)
{
    libusb_hotplug_register_callback(
        reinterpret_cast< libusb_context * >( _contextImpl )
        , LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED | LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT
        , LIBUSB_HOTPLUG_ENUMERATE
        , _VENDOR_ID
        , _PRODUCT_ID
        , LIBUSB_HOTPLUG_MATCH_ANY
        , reinterpret_cast< libusb_hotplug_callback_fn >( _callbackUsbHotplugImpl )
        , _userData
        , nullptr
    );
}

void handleUsbEventsImpl(
    UsbContextImpl *    _contextImpl
)
{
    libusb_handle_events( reinterpret_cast< libusb_context * >( _contextImpl ) );
}

int bulkTransferUsbImpl(
    UsbDeviceHandleImpl *   _deviceHandleImpl
    , unsigned char         _ENDPOINT
    , void *                _data
    , int                   _DATA_SIZE
)
{
    auto    transferred = 0;

    const auto  ERROR_CODE = libusb_bulk_transfer(
        reinterpret_cast< libusb_device_handle * >( _deviceHandleImpl )
        , _ENDPOINT
        , static_cast< unsigned char * >( _data )
        , _DATA_SIZE
        , &transferred
        , TIMEOUT_BULK_TRANSFER
    );
    if( ERROR_CODE != 0 ) {
        return ERROR_CODE;
    }

    return transferred;
}
