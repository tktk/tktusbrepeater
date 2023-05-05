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
    static int callbackUsbHotplug(
        UsbContextImpl *
        , UsbDeviceImpl *
        , UsbHotplugEvent
        , void *
    );

    UsbDeviceManager(
        UsbContextImplUnique
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

UsbDeviceManagerUnique newUsbDeviceManager(
    int
    , int
);

#endif  // TKTUSBREPEATER_USBDEVICEMANAGER_H
