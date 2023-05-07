#ifndef TKTUSBREPEATER_IMPL_USB_MOCK_H
#define TKTUSBREPEATER_IMPL_USB_MOCK_H

#include "tktusbrepeater/impl/usb.h"

// openUsbDeviceImpl()
struct ArgsOpenUsbDeviceImpl
{
    UsbDeviceImpl * device = nullptr;
};

extern int  calledCountOpenUsbDeviceImpl;

extern ArgsOpenUsbDeviceImpl    argsOpenUsbDeviceImpl;

extern UsbDeviceHandleImpl *    returnsOpenUsbDeviceImpl;

// initializeUsbContextImpl()
extern UsbContextImpl * returnsInitializeUsbContextImpl;

// registerCallbackUsbHotplugImpl()
struct ArgsRegisterCallbackUsbHotplugImpl
{
    UsbContextImpl *        context = nullptr;
    int                     vendorId = 0;
    int                     productId = 0;
    CallbackUsbHotplugImpl  callback = nullptr;
    void *                  userData = nullptr;
};

extern int  calledCountRegisterCallbackUsbHotplugImpl;

extern ArgsRegisterCallbackUsbHotplugImpl   argsRegisterCallbackUsbHotplugImpl;

// handleUsbEventsImpl()
struct ArgsHandleUsbEventsImpl
{
    UsbContextImpl *    context = nullptr;
};

extern int  calledCountHandleUsbEventsImpl;

extern ArgsHandleUsbEventsImpl  argsHandleUsbEventsImpl;

// bulkTrandferUsbImpl()
struct ArgsBulkTransferUsbImpl
{
    UsbDeviceHandleImpl *   deviceHandle = nullptr;
    unsigned char           endpoint = 0;
    void *                  data = nullptr;
    int                     dataSize = 0;
};

extern int  calledCountBulkTransferUsbImpl;

extern ArgsBulkTransferUsbImpl  argsBulkTransferUsbImpl;

extern int  returnsBulkTransferUsbImpl;


void initializeUsbMock(
);

#endif  // TKTUSBREPEATER_IMPL_USB_MOCK_H
