#ifndef TKTUSBREPEATER_USBDEVICEMANAGER_H
#define TKTUSBREPEATER_USBDEVICEMANAGER_H

#include "tktusbrepeater/impl/usb.h"
#include <shared_mutex>
#include <memory>
#include <ctime>

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

private:
    void callbackUsbHotplugArrived(
        UsbDeviceImpl *
    );

    void callbackUsbHotplugLeft(
        UsbDeviceImpl *
    );

public:
    UsbDeviceManager(
        UsbContextImplUnique
    );

    void lockEventWaiters(
    );

    void unlockEventWaiters(
    );

    void lockEvents(
    );

    void unlockEvents(
    );

    void handleEvents(
        std::time_t
    );

    //REMOVEME
    void handleEvents(
    );

    int bulkTransfer(
        unsigned char
        , void *
        , int
    );
};

using UsbDeviceManagerUnique = std::unique_ptr< UsbDeviceManager >;

UsbDeviceManagerUnique newUsbDeviceManager(
    int
    , int
);

#endif  // TKTUSBREPEATER_USBDEVICEMANAGER_H
