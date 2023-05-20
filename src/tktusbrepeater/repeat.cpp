#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/socket.h"

void repeat(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , int                   _socket
)
{
    //TODO
}

bool readEndpoint(
    unsigned char & _endpoint
    , Socket &      _socket
)
{
    auto    endpoint = static_cast< unsigned char >( 0 );

    if( _socket.read(
        &endpoint
        , 1
    ) < 1 ) {
        return false;
    }

    _endpoint = endpoint;

    return true;
}

bool repeatFromUsbDevice(
    unsigned char           _ENDPOINT
    , UsbDeviceManager &    _usbDeviceManager
    , Socket &              _socket
    , void *                _buffer
    , int                   _BUFFER_SIZE
)
{
    //TODO
    return false;
}

bool repeatToUsbDevice(
    unsigned char           _ENDPOINT
    , UsbDeviceManager &    _usbDeviceManager
    , Socket &              _socket
    , void *                _buffer
    , int                   _BUFFER_SIZE
)
{
    const auto  READ_SIZE = _socket.read(
        _buffer
        , _BUFFER_SIZE
    );
    //TODO READ_SIZEのチェック

    const auto  TRANSFERRED_SIZE = _usbDeviceManager.bulkTransfer(
        _ENDPOINT
        , _buffer
        , READ_SIZE
    );

    _socket.write(
        &TRANSFERRED_SIZE
        , 2
    );

    return true;
}
