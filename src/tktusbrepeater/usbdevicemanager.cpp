#include "tktusbrepeater/usbdevicemanager.h"
#include <stdexcept>

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
    auto    managerUnique = UsbDeviceManagerUnique( new UsbDeviceManager() );

    if( registerUsbHotplugCallback(
        _context
        , _VENDOR_ID
        , _PRODUCT_ID
        , managerUnique.get()
    ) != 0 ) {
        throw std::runtime_error( "registerUsbHotplugCallback()が失敗" );
    }

    return managerUnique;
}
