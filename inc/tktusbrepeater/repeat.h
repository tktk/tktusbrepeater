#ifndef TKTUSBREPEATER_REPEAT_H
#define TKTUSBREPEATER_REPEAT_H

#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/socket.h"

bool readEndpoint(
    unsigned char &
    , Socket &
);

bool repeatFromUsbDevice(
    unsigned char
    , UsbDeviceManager &
    , Socket &
    , void *
    , int
);

bool repeatToUsbDevice(
    unsigned char
    , UsbDeviceManager &
    , Socket &
    , void *
    , int
);

#endif  // TKTUSBREPEATER_REPEAT_H
