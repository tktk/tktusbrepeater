#ifndef TKTUSBREPEATER_IMPL_USB_H
#define TKTUSBREPEATER_IMPL_USB_H

#include <memory>

class UsbDeviceImpl;

class UsbDeviceHandleImpl;

void closeUsbDeviceHandleImpl(
    UsbDeviceHandleImpl *
);

struct CloseUsbDeviceHandleImpl
{
    void operator()(
        UsbDeviceHandleImpl *   _handlePtr
    ) const
    {
        closeUsbDeviceHandleImpl( _handlePtr );
    }
};

using UsbDeviceHandleImplUnique = std::unique_ptr<
    UsbDeviceHandleImpl
    , CloseUsbDeviceHandleImpl
>;

UsbDeviceHandleImplUnique openUsbDeviceImpl(
    UsbDeviceImpl *
);

enum UsbHotplugEvent {
    ARRIVED = 0x1,
    LEFT = 0x2,
};

class UsbContextImpl;

void exitUsbContextImpl(
    UsbContextImpl *
);

struct ExitUsbContextImpl
{
    void operator()(
        UsbContextImpl *    _contextPtr
    ) const
    {
        exitUsbContextImpl( _contextPtr );
    }
};

using UsbContextImplUnique = std::unique_ptr<
    UsbContextImpl
    , ExitUsbContextImpl
>;

UsbContextImplUnique initializeUsbContextImpl(
);

using CallbackUsbHotplugImpl = int ( * )(
    UsbContextImpl *
    , UsbDeviceImpl *
    , UsbHotplugEvent
    , void *
);

void registerCallbackUsbHotplugImpl(
    UsbContextImpl *
    , int
    , int
    , CallbackUsbHotplugImpl
    , void *
);

#endif  // TKTUSBREPEATER_IMPL_USB_H
