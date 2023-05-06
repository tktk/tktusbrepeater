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
        callbackUsbHotplugArrived(
            _devicePtr
            , managerPtr
        );
    } else {
        callbackUsbHotplugLeft( managerPtr );
    }

    return 0;
}

void UsbDeviceManager::callbackUsbHotplugArrived(
    UsbDeviceImpl *         _devicePtr
    , UsbDeviceManager *    _managerPtr
)
{
    if( _managerPtr->usbDevicePtr != nullptr ) {
        return;
    }

    auto    usbDeviceHandleUnique = openUsbDeviceImpl( _devicePtr );

    _managerPtr->usbDevicePtr = _devicePtr;

    auto    lock = std::lock_guard< std::shared_mutex >( _managerPtr->usbDeviceMutex );

    _managerPtr->usbDeviceHandleUnique = std::move( usbDeviceHandleUnique );
}

void UsbDeviceManager::callbackUsbHotplugLeft(
    UsbDeviceManager *  _managerPtr
)
{
    _managerPtr->usbDevicePtr = nullptr;

    auto    lock = std::lock_guard< std::shared_mutex >( _managerPtr->usbDeviceMutex );

    _managerPtr->usbDeviceHandleUnique.reset();
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
