#include "tktusbrepeater/impl/usb_mock.h"

int calledCountRegisterUsbHotplugCallback;

ArgsRegisterUsbHotplugCallback  argsRegisterUsbHotplugCallback;

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
)
{
}

void registerUsbHotplugCallback(
    UsbContextImpl *        _context
    , int                   _vendorId
    , int                   _productId
    , CallbackUsbHotplug    _callback
    , void *                _userData
)
{
    calledCountRegisterUsbHotplugCallback++;

    argsRegisterUsbHotplugCallback.context = _context;
    argsRegisterUsbHotplugCallback.vendorId = _vendorId;
    argsRegisterUsbHotplugCallback.productId = _productId;
    argsRegisterUsbHotplugCallback.callback = _callback;
    argsRegisterUsbHotplugCallback.userData = _userData;
}

UsbContextImpl * returnsInitializeUsbContextImpl;

void exitUsbContextImpl(
    UsbContextImpl *
)
{
}

UsbContextImplUnique initializeUsbContextImpl(
)
{
    return UsbContextImplUnique( returnsInitializeUsbContextImpl );
}

namespace {
    void initializeMockRegisterUsbHotplugCallback(
    )
    {
        calledCountRegisterUsbHotplugCallback = 0;
        argsRegisterUsbHotplugCallback = ArgsRegisterUsbHotplugCallback();
    }

    void initializeMockInitializeUsbContextImpl(
    )
    {
        returnsInitializeUsbContextImpl = nullptr;
    }
}

void initializeUsbMock(
)
{
    initializeMockRegisterUsbHotplugCallback();
    initializeMockInitializeUsbContextImpl();
}
