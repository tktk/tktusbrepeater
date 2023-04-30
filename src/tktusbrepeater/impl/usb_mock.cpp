#include "tktusbrepeater/impl/usb_mock.h"

int registerUsbHotplugCallbackCalledCount;

int registerUsbHotplugCallbackReturns;

RegisterUsbHotplugCallbackArgs  registerUsbHotplugCallbackArgs;

int registerUsbHotplugCallback(
    UsbContextImpl *    _context
    , int               _vendorId
    , int               _productId
    , void *            _userData
)
{
    registerUsbHotplugCallbackCalledCount++;

    registerUsbHotplugCallbackArgs.context = _context;
    registerUsbHotplugCallbackArgs.vendorId = _vendorId;
    registerUsbHotplugCallbackArgs.productId = _productId;
    registerUsbHotplugCallbackArgs.userData = _userData;

    return registerUsbHotplugCallbackReturns;
}

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
)
{
}

namespace {
    void initializeRegisterUsbHotplugCallbackMock(
    )
    {
        registerUsbHotplugCallbackCalledCount = 0;
        registerUsbHotplugCallbackReturns = 0;
        registerUsbHotplugCallbackArgs = RegisterUsbHotplugCallbackArgs();
    }
}

void initializeUsbMock(
)
{
    initializeRegisterUsbHotplugCallbackMock();
}
