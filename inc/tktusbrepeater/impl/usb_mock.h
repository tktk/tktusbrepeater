#ifndef TKTUSBREPEATER_IMPL_USB_MOCK_H
#define TKTUSBREPEATER_IMPL_USB_MOCK_H

#include "tktusbrepeater/impl/usb.h"

struct RegisterUsbHotplugCallbackArgs
{
    UsbContextImpl *    context = nullptr;
    int                 vendorId = 0;
    int                 productId = 0;
    void *              userData = nullptr;
};

extern int  registerUsbHotplugCallbackCalledCount;

extern int  registerUsbHotplugCallbackReturns;

extern RegisterUsbHotplugCallbackArgs   registerUsbHotplugCallbackArgs;

void initializeUsbMock(
);

#endif  // TKTUSBREPEATER_IMPL_USB_MOCK_H
