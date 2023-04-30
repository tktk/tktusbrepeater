#include "tktusbrepeater/usbdevicemanager.h"

UsbDeviceManager::UsbDeviceManager(
)
{
}

void UsbDeviceManager::procEvents(
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
    UsbContextImpl *    _context
    , int               _VENDOR_ID
    , int               _PRODUCT_ID
)
{
    //TODO
    return nullptr;
}
