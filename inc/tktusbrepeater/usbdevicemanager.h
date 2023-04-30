#ifndef TKTUSBREPEATER_USBDEVICEMANAGER_H
#define TKTUSBREPEATER_USBDEVICEMANAGER_H

#include "tktusbrepeater/impl/usb.h"
#include <shared_mutex>
#include <memory>

int callbackUsbHotplug(
    UsbContextImpl *
    , UsbDeviceImpl *
    , UsbHotplugEvent
    , void *
);

class UsbDeviceManager
{
    UsbContextImplUnique    usbContextUnique;

    UsbDeviceImpl * usbDevicePtr;

    std::shared_mutex           usbDeviceMutex;
    UsbDeviceHandleImplUnique   usbDeviceHandleUnique;

public:
    UsbDeviceManager(
    );

    void handleEvents(
    );

    int readData(
        void *
        , int
    );

    int writeData(
        void *
        , int
    );
};

using UsbDeviceManagerUnique = std::unique_ptr< UsbDeviceManager >;

//REMOVEME
UsbDeviceManagerUnique newUsbDeviceManager(
    UsbContextImpl *
    , int
    , int
);

UsbDeviceManagerUnique newUsbDeviceManager(
    int
    , int
);

#endif  // TKTUSBREPEATER_USBDEVICEMANAGER_H
