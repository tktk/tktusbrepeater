#ifndef TKTUSBREPEATER_IMPL_USB_MOCK_H
#define TKTUSBREPEATER_IMPL_USB_MOCK_H

#include "tktusbrepeater/impl/usb.h"

// openUsbDeviceImpl()
struct ArgsOpenUsbDeviceImpl
{
    UsbDeviceImpl * device = nullptr;
};

extern ArgsOpenUsbDeviceImpl    argsOpenUsbDeviceImpl;

extern UsbDeviceHandleImpl *    returnsOpenUsbDeviceImpl;

// initializeUsbContextImpl()
extern UsbContextImpl * returnsInitializeUsbContextImpl;

// registerUsbHotplugCallback()
struct ArgsRegisterUsbHotplugCallback
{
    UsbContextImpl *    context = nullptr;
    int                 vendorId = 0;
    int                 productId = 0;
    CallbackUsbHotplug  callback = nullptr;
    void *              userData = nullptr;
};

extern int  calledCountRegisterUsbHotplugCallback;

extern ArgsRegisterUsbHotplugCallback   argsRegisterUsbHotplugCallback;


void initializeUsbMock(
);

#endif  // TKTUSBREPEATER_IMPL_USB_MOCK_H
