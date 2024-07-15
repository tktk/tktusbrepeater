#ifndef TKTUSBREPEATER_IMPL_USB_MOCK_H
#define TKTUSBREPEATER_IMPL_USB_MOCK_H

#include "tktusbrepeater/impl/usb.h"

#include <ctime>

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

// lockEventWaitersImpl()
struct ArgsLockEventWaitersImpl
{
    UsbContextImpl *    context = nullptr;
};

extern int  calledCountLockEventWaitersImpl;

extern ArgsLockEventWaitersImpl argsLockEventWaitersImpl;

// unlockEventWaitersImpl()
struct ArgsUnlockEventWaitersImpl
{
    UsbContextImpl *    context = nullptr;
};

extern int  calledCountUnlockEventWaitersImpl;

extern ArgsUnlockEventWaitersImpl   argsUnlockEventWaitersImpl;

// lockEventsImpl()
struct ArgsLockEventsImpl
{
    UsbContextImpl *    context = nullptr;
};

extern int  calledCountLockEventsImpl;

extern ArgsLockEventsImpl   argsLockEventsImpl;

// unlockEventsImpl()
struct ArgsUnlockEventsImpl
{
    UsbContextImpl *    context = nullptr;
};

extern int  calledCountUnlockEventsImpl;

extern ArgsUnlockEventsImpl argsUnlockEventsImpl;

// handleUsbEventsLockedImpl()
struct ArgsHandleUsbEventsLockedImpl
{
    UsbContextImpl *    context = nullptr;
    std::time_t         waitingSeconds = 0;
};

extern int  calledCountHandleUsbEventsLockedImpl;

extern ArgsHandleUsbEventsLockedImpl    argsHandleUsbEventsLockedImpl;

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
