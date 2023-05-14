#ifndef TKTUSBREPEATER_REPEAT_H
#define TKTUSBREPEATER_REPEAT_H

#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/socket.h"

void repeat(
    UsbEndpointManager &
    , UsbDeviceManager &
    , int
);

bool readEndpoint(
    unsigned char &
    , Socket &
);

bool repeatFromUsbDevice(
    unsigned char
    , UsbDeviceManager &
    , Socket &
);

bool repeatToUsbDevice(
    unsigned char
    , UsbDeviceManager &
    , Socket &
);

#endif  // TKTUSBREPEATER_REPEAT_H
