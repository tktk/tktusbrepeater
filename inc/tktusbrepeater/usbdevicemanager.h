#ifndef TKTUSBREPEATER_USBDEVICEMANAGER_H
#define TKTUSBREPEATER_USBDEVICEMANAGER_H

#include "tktusbrepeater/impl/usb.h"
#include <shared_mutex>
#include <memory>

class UsbDeviceManager
{
    UsbDeviceImpl * usbDevicePtr;

    std::shared_mutex           usbDeviceMutex;
    UsbDeviceHandleImplUnique   usbDeviceHandleUnique;

public:
    UsbDeviceManager(
    );

    void procEvents(
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
    UsbContextImpl *
    , int
    , int
);

#endif  // TKTUSBREPEATER_USBDEVICEMANAGER_H
