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

    auto    usbDeviceHandleUnique = openUsbDeviceImpl( _devicePtr );

    managerPtr->usbDevicePtr = _devicePtr;

    auto    lock = std::lock_guard< std::shared_mutex >( managerPtr->usbDeviceMutex );

    managerPtr->usbDeviceHandleUnique = std::move( usbDeviceHandleUnique );

    return 0;
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
    //TODO
}

int UsbDeviceManager::readData(
    void *  _data
    , int   _DATA_SIZE
)
{
    //TODO
    return -1;
}

int UsbDeviceManager::writeData(
    void *  _DATA
    , int   _DATA_SIZE
)
{
    //TODO
    return -1;
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

    registerUsbHotplugCallback(
        contextPtr
        , _VENDOR_ID
        , _PRODUCT_ID
        , UsbDeviceManager::callbackUsbHotplug
        , managerUnique.get()
    );

    return managerUnique;
}
