#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/impl/usb.h"
#include <stdexcept>

int callbackUsbHotplug(
    UsbContextImpl *
    , UsbDeviceImpl *
    , UsbHotplugEvent
    , void *
)
{
    //TODO
    return 0;
}

UsbDeviceManager::UsbDeviceManager(
)
    : usbDevicePtr( nullptr )
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

//REMOVEME
UsbDeviceManagerUnique newUsbDeviceManager(
    UsbContextImpl *    _context
    , int               _VENDOR_ID
    , int               _PRODUCT_ID
)
{
    auto    managerUnique = UsbDeviceManagerUnique( new UsbDeviceManager() );

/*
    registerUsbHotplugCallback(
        _context
        , _VENDOR_ID
        , _PRODUCT_ID
        , managerUnique.get()
    );
*/

    return managerUnique;
}

UsbDeviceManagerUnique newUsbDeviceManager(
    int     _VENDOR_ID
    , int   _PRODUCT_ID
)
{
    //TODO
    return nullptr;
}
