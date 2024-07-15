#include "tktusbrepeater/impl/usb_mock.h"
#include <ctime>
#include <stdexcept>

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

int calledCountHandleUsbEventsTimeoutCompletedImpl;

ArgsHandleUsbEventsTimeoutCompletedImpl argsHandleUsbEventsTimeoutCompletedImpl;

void handleUsbEventsTimeoutCompletedImpl(
    UsbContextImpl *    _context
    , std::time_t       _WAITING_SECONDS
    , int *             _completed
)
{
    calledCountHandleUsbEventsTimeoutCompletedImpl++;

    argsHandleUsbEventsTimeoutCompletedImpl.context = _context;
    argsHandleUsbEventsTimeoutCompletedImpl.waitingSeconds = _WAITING_SECONDS;
    argsHandleUsbEventsTimeoutCompletedImpl.completed = _completed;
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

    void initializeMockHandleUsbEventsTimeoutCompletedImpl(
    )
    {
        calledCountHandleUsbEventsTimeoutCompletedImpl = 0;
        argsHandleUsbEventsTimeoutCompletedImpl = ArgsHandleUsbEventsTimeoutCompletedImpl();
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
    initializeMockHandleUsbEventsTimeoutCompletedImpl();
    initializeMockBulkTransferUsbImpl();
}
