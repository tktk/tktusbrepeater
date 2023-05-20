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
    const auto  TRANSFERRED_SIZE = _usbDeviceManager.bulkTransfer(
        _ENDPOINT
        , _buffer
        , _BUFFER_SIZE
    );
    if( TRANSFERRED_SIZE <= 0 ) {
        return _socket.isConnected();
    }

    //TODO 戻り値をチェック
    _socket.write(
        _buffer
        , TRANSFERRED_SIZE
    );

    return true;
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
    if( READ_SIZE < 0 ) {
        return false;
    }

    _usbDeviceManager.bulkTransfer(
        _ENDPOINT
        , _buffer
        , READ_SIZE
    );

    return true;
}
