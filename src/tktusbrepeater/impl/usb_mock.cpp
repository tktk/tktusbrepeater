#include "tktusbrepeater/impl/usb_mock.h"

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
)
{
}

ArgsOpenUsbDeviceImpl   argsOpenUsbDeviceImpl;

UsbDeviceHandleImpl *   returnsOpenUsbDeviceImpl;

UsbDeviceHandleImplUnique openUsbDeviceImpl(
    UsbDeviceImpl * _device
)
{
    argsOpenUsbDeviceImpl.device = _device;

    return UsbDeviceHandleImplUnique( returnsOpenUsbDeviceImpl );
}

void exitUsbContextImpl(
    UsbContextImpl *
)
{
}

UsbContextImpl * returnsInitializeUsbContextImpl;

UsbContextImplUnique initializeUsbContextImpl(
)
{
    return UsbContextImplUnique( returnsInitializeUsbContextImpl );
}

int calledCountRegisterUsbHotplugCallback;

ArgsRegisterUsbHotplugCallback  argsRegisterUsbHotplugCallback;

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

namespace {
    void initializeMockOpenUsbDeviceImpl(
    )
    {
        argsOpenUsbDeviceImpl = ArgsOpenUsbDeviceImpl();
        returnsOpenUsbDeviceImpl = nullptr;
    }

    void initializeMockInitializeUsbContextImpl(
    )
    {
        returnsInitializeUsbContextImpl = nullptr;
    }

    void initializeMockRegisterUsbHotplugCallback(
    )
    {
        calledCountRegisterUsbHotplugCallback = 0;
        argsRegisterUsbHotplugCallback = ArgsRegisterUsbHotplugCallback();
    }
}

void initializeUsbMock(
)
{
    initializeMockOpenUsbDeviceImpl();
    initializeMockInitializeUsbContextImpl();
    initializeMockRegisterUsbHotplugCallback();
}
