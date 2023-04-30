#ifndef TKTUSBREPEATER_IMPL_USB_H
#define TKTUSBREPEATER_IMPL_USB_H

#include <memory>

using UsbDeviceImpl = void;

using UsbDeviceHandleImpl = void;

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

using UsbContextImpl = void;

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

using CallbackUsbHotplug = int ( * )(
    UsbContextImpl *
    , UsbDeviceImpl *
    , UsbHotplugEvent
    , void *
);

void registerUsbHotplugCallback(
    UsbContextImpl *
    , int
    , int
    , CallbackUsbHotplug
    , void *
);

#endif  // TKTUSBREPEATER_IMPL_USB_H
