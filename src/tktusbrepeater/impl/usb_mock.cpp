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

bool    waitersLocked = false;

int calledCountLockEventWaitersImpl;

ArgsLockEventWaitersImpl    argsLockEventWaitersImpl;

void lockEventWaitersImpl(
    UsbContextImpl *    _context
)
{
    if( waitersLocked == true ) {
        throw std::runtime_error( "ロック中にlockEventWaitersImpl()" );
    }

    waitersLocked = true;

    calledCountLockEventWaitersImpl++;

    argsLockEventWaitersImpl.context = _context;
}

int calledCountUnlockEventWaitersImpl;

ArgsUnlockEventWaitersImpl  argsUnlockEventWaitersImpl;

void unlockEventWaitersImpl(
    UsbContextImpl *    _context
)
{
    if( waitersLocked == false ) {
        throw std::runtime_error( "アンロック中にunlockEventWaitersImpl()" );
    }

    waitersLocked = false;

    calledCountUnlockEventWaitersImpl++;

    argsUnlockEventWaitersImpl.context = _context;
}

bool    locked = false;

int calledCountLockEventsImpl;

ArgsLockEventsImpl  argsLockEventsImpl;

void lockEventsImpl(
    UsbContextImpl *    _context
)
{
    if( locked == true ) {
        throw std::runtime_error( "ロック中にlockEventsImpl()" );
    }

    locked = true;

    calledCountLockEventsImpl++;

    argsLockEventsImpl.context = _context;
}

int calledCountUnlockEventsImpl;

ArgsUnlockEventsImpl    argsUnlockEventsImpl;

void unlockEventsImpl(
    UsbContextImpl *    _context
)
{
    if( locked == false ) {
        throw std::runtime_error( "アンロック中にlockEventsImpl()" );
    }

    locked = false;

    calledCountUnlockEventsImpl++;

    argsUnlockEventsImpl.context = _context;
}

int calledCountHandleUsbEventsLockedImpl;

ArgsHandleUsbEventsLockedImpl   argsHandleUsbEventsLockedImpl;

void handleUsbEventsLockedImpl(
    UsbContextImpl *    _context
    , std::time_t       _WAITING_SECONDS
)
{
    if( locked == false ) {
        throw std::runtime_error( "アンロック中にhandleUsbEventsLockedImpl()" );
    }

    calledCountHandleUsbEventsLockedImpl++;

    argsHandleUsbEventsLockedImpl.context = _context;
    argsHandleUsbEventsLockedImpl.waitingSeconds = _WAITING_SECONDS;
}

//REMOVEME
void handleUsbEventsImpl(
    UsbContextImpl *    _context
)
{
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

    void initializeMockLockEventWaitersImpl(
    )
    {
        calledCountLockEventWaitersImpl = 0;
        argsLockEventWaitersImpl = ArgsLockEventWaitersImpl();
    }

    void initializeMockUnlockEventWaitersImpl(
    )
    {
        calledCountUnlockEventWaitersImpl = 0;
        argsUnlockEventWaitersImpl = ArgsUnlockEventWaitersImpl();
    }

    void initializeMockLockEventsImpl(
    )
    {
        calledCountLockEventsImpl = 0;
        argsLockEventsImpl = ArgsLockEventsImpl();
    }

    void initializeMockUnlockEventsImpl(
    )
    {
        calledCountUnlockEventsImpl = 0;
        argsUnlockEventsImpl = ArgsUnlockEventsImpl();
    }

    void initializeMockHandleUsbEventsLockedImpl(
    )
    {
        calledCountHandleUsbEventsLockedImpl = 0;
        argsHandleUsbEventsLockedImpl = ArgsHandleUsbEventsLockedImpl();
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
    initializeMockLockEventWaitersImpl();
    initializeMockUnlockEventWaitersImpl();
    initializeMockLockEventsImpl();
    initializeMockUnlockEventsImpl();
    initializeMockHandleUsbEventsLockedImpl();
    initializeMockBulkTransferUsbImpl();
}
