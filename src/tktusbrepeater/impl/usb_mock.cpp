#include "tktusbrepeater/impl/usb_mock.h"

int calledCountRegisterUsbHotplugCallback;

int returnsRegisterUsbHotplugCallback;

ArgsRegisterUsbHotplugCallback  argsRegisterUsbHotplugCallback;

int registerUsbHotplugCallback(
    UsbContextImpl *    _context
    , int               _vendorId
    , int               _productId
    , void *            _userData
)
{
    calledCountRegisterUsbHotplugCallback++;

    argsRegisterUsbHotplugCallback.context = _context;
    argsRegisterUsbHotplugCallback.vendorId = _vendorId;
    argsRegisterUsbHotplugCallback.productId = _productId;
    argsRegisterUsbHotplugCallback.userData = _userData;

    return returnsRegisterUsbHotplugCallback;
}

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
)
{
}

namespace {
    void initializeMockRegisterUsbHotplugCallback(
    )
    {
        calledCountRegisterUsbHotplugCallback = 0;
        returnsRegisterUsbHotplugCallback = 0;
        argsRegisterUsbHotplugCallback = ArgsRegisterUsbHotplugCallback();
    }
}

void initializeUsbMock(
)
{
    initializeMockRegisterUsbHotplugCallback();
}
