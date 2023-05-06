#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb.h"
#include <stdexcept>

int UsbDeviceManager::callbackUsbHotplug(
    UsbContextImpl *
    , UsbDeviceImpl *
    , UsbHotplugEvent
    , void *
)
{
    //TODO
    return -1;
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
