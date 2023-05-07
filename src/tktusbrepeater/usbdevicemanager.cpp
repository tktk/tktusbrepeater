#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb.h"
#include <mutex>
#include <shared_mutex>
#include <stdexcept>

int UsbDeviceManager::callbackUsbHotplug(
    UsbContextImpl *
    , UsbDeviceImpl *   _devicePtr
    , UsbHotplugEvent   _EVENT
    , void *            _managerPtr
)
{
    auto    managerPtr = static_cast< UsbDeviceManager * >( _managerPtr );

    if( _EVENT == UsbHotplugEvent::ARRIVED ) {
        managerPtr->callbackUsbHotplugArrived( _devicePtr );
    } else {
        managerPtr->callbackUsbHotplugLeft( _devicePtr );
    }

    return 0;
}

void UsbDeviceManager::callbackUsbHotplugArrived(
    UsbDeviceImpl * _devicePtr
)
{
    if( this->usbDevicePtr != nullptr ) {
        return;
    }

    auto    usbDeviceHandleUnique = openUsbDeviceImpl( _devicePtr );
    if( usbDeviceHandleUnique.get() == nullptr ) {
        return;
    }

    this->usbDevicePtr = _devicePtr;

    auto    lock = std::lock_guard< std::shared_mutex >( this->usbDeviceMutex );

    this->usbDeviceHandleUnique = std::move( usbDeviceHandleUnique );
}

void UsbDeviceManager::callbackUsbHotplugLeft(
    UsbDeviceImpl * _devicePtr
)
{
    if( this->usbDevicePtr != _devicePtr ) {
        return;
    }

    this->usbDevicePtr = nullptr;

    auto    lock = std::lock_guard< std::shared_mutex >( this->usbDeviceMutex );

    this->usbDeviceHandleUnique.reset();
}

UsbDeviceManager::UsbDeviceManager(
    UsbContextImplUnique    _contextUnique
)
    : usbContextUnique( std::move( _contextUnique ) )
    , usbDevicePtr( nullptr )
{
}

void UsbDeviceManager::handleEvents(
)
{
    handleUsbEventsImpl( this->usbContextUnique.get() );
}

int UsbDeviceManager::bulkTransfer(
    unsigned char   _ENDPOINT
    , void *        _data
    , int           _DATA_SIZE
)
{
    auto    lock = std::shared_lock< std::shared_mutex >( this->usbDeviceMutex );

    auto    usbDeviceHandlePtr = this->usbDeviceHandleUnique.get();
    if( usbDeviceHandlePtr == nullptr ) {
        return 0;
    }

    return bulkTransferUsbImpl(
        usbDeviceHandlePtr
        , _ENDPOINT
        , _data
        , _DATA_SIZE
    );
}

UsbDeviceManagerUnique newUsbDeviceManager(
    int     _VENDOR_ID
    , int   _PRODUCT_ID
)
{
    auto    contextUnique = initializeUsbContextImpl();
    auto    contextPtr = contextUnique.get();

    auto    managerUnique = UsbDeviceManagerUnique(
        new UsbDeviceManager(
            std::move( contextUnique )
        )
    );

    registerCallbackUsbHotplugImpl(
        contextPtr
        , _VENDOR_ID
        , _PRODUCT_ID
        , UsbDeviceManager::callbackUsbHotplug
        , managerUnique.get()
    );

    return managerUnique;
}
