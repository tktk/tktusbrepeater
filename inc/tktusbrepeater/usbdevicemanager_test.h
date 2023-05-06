#ifndef TKTUSBREPEATER_USBDEVICEMANAGER_TEST_H
#define TKTUSBREPEATER_USBDEVICEMANAGER_TEST_H

#include "tktusbrepeater/impl/usb.h"
#include <shared_mutex>

struct UsbDeviceManagerImpl
{
    UsbContextImplUnique    usbContextUnique;

    UsbDeviceImpl * usbDevicePtr;

    std::shared_mutex           usbDeviceMutex;
    UsbDeviceHandleImplUnique   usbDeviceHandleUnique;
};

#endif  // TKTUSBREPEATER_USBDEVICEMANAGER_TEST_H
