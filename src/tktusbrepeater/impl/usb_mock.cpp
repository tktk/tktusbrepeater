#include "tktusbrepeater/impl/usb_mock.h"

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
)
{
}

int  calledCountOpenUsbDeviceImpl;

ArgsOpenUsbDeviceImpl   argsOpenUsbDeviceImpl;

UsbDeviceHandleImpl *   returnsOpenUsbDeviceImpl;

UsbDeviceHandleImplUnique openUsbDeviceImpl(
    UsbDeviceImpl * _device
)
{
    calledCountOpenUsbDeviceImpl++;

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

int calledCountRegisterCallbackUsbHotplugImpl;

ArgsRegisterCallbackUsbHotplugImpl  argsRegisterCallbackUsbHotplugImpl;

void registerCallbackUsbHotplugImpl(
    UsbContextImpl *            _context
    , int                       _vendorId
    , int                       _productId
    , CallbackUsbHotplugImpl    _callback
    , void *                    _userData
)
{
    calledCountRegisterCallbackUsbHotplugImpl++;

    argsRegisterCallbackUsbHotplugImpl.context = _context;
    argsRegisterCallbackUsbHotplugImpl.vendorId = _vendorId;
    argsRegisterCallbackUsbHotplugImpl.productId = _productId;
    argsRegisterCallbackUsbHotplugImpl.callback = _callback;
    argsRegisterCallbackUsbHotplugImpl.userData = _userData;
}

namespace {
    void initializeMockOpenUsbDeviceImpl(
    )
    {
        calledCountOpenUsbDeviceImpl = 0;
        argsOpenUsbDeviceImpl = ArgsOpenUsbDeviceImpl();
        returnsOpenUsbDeviceImpl = nullptr;
    }

    void initializeMockInitializeUsbContextImpl(
    )
    {
        returnsInitializeUsbContextImpl = nullptr;
    }

    void initializeMockRegisterCallbackUsbHotplugImpl(
    )
    {
        calledCountRegisterCallbackUsbHotplugImpl = 0;
        argsRegisterCallbackUsbHotplugImpl = ArgsRegisterCallbackUsbHotplugImpl();
    }
}

void initializeUsbMock(
)
{
    initializeMockOpenUsbDeviceImpl();
    initializeMockInitializeUsbContextImpl();
    initializeMockRegisterCallbackUsbHotplugImpl();
}
