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

int calledCountHandleUsbEventsImpl;

ArgsHandleUsbEventsImpl argsHandleUsbEventsImpl;

void handleUsbEventsImpl(
    UsbContextImpl *    _context
)
{
    calledCountHandleUsbEventsImpl++;

    argsHandleUsbEventsImpl.context = _context;
}

int calledCountBulkTransferUsbImpl;

ArgsBulkTransferUsbImpl argsBulkTransferUsbImpl;

int returnsBulkTransferUsbImpl;

int bulkTransferUsbImpl(
    UsbDeviceHandleImpl *   _deviceHandle
    , unsigned char         _endpoint
    , void *                _data
    , int                   _dataSize
)
{
    calledCountBulkTransferUsbImpl++;

    argsBulkTransferUsbImpl.deviceHandle = _deviceHandle;
    argsBulkTransferUsbImpl.endpoint = _endpoint;
    argsBulkTransferUsbImpl.data = _data;
    argsBulkTransferUsbImpl.dataSize = _dataSize;

    return returnsBulkTransferUsbImpl;
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

    void initializeMockHandleUsbEventsImpl(
    )
    {
        calledCountHandleUsbEventsImpl = 0;
        argsHandleUsbEventsImpl = ArgsHandleUsbEventsImpl();
    }

    void initializeMockBulkTransferUsbImpl(
    )
    {
        calledCountBulkTransferUsbImpl = 0;
        argsBulkTransferUsbImpl = ArgsBulkTransferUsbImpl();
        returnsBulkTransferUsbImpl = 0;
    }
}

void initializeUsbMock(
)
{
    initializeMockOpenUsbDeviceImpl();
    initializeMockInitializeUsbContextImpl();
    initializeMockRegisterCallbackUsbHotplugImpl();
    initializeMockHandleUsbEventsImpl();
    initializeMockBulkTransferUsbImpl();
}
