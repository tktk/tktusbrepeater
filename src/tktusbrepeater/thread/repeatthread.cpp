#include "tktusbrepeater/thread/repeatthread.h"
#include "tktusbrepeater/thread/endmanager.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/repeat.h"
#include "tktusbrepeater/usb.h"
#include <array>
#include <thread>

namespace {
    enum {
        BUFFER_SIZE = 1024,
    };

    using Buffer = std::array<
        char
        , BUFFER_SIZE
    >;

    bool repeatFromUsbDeviceWithEndCheck(
        unsigned char           _ENDPOINT
        , UsbDeviceManager &    _usbDeviceManager
        , Socket &              _socket
        , void *                _buffer
        , int                   _BUFFER_SIZE
        , EndManager &          _endManager
        , int                   _WAITING_MILLISECONDS
    )
    {
        while( 1 ) {
            if( _endManager.isEnd() == true ) {
                return false;
            } else if( _socket.pollOut( _WAITING_MILLISECONDS ) == true ) {
                break;
            }
        }

        return repeatFromUsbDevice(
            _ENDPOINT
            , _usbDeviceManager
            , _socket
            , _buffer
            , _BUFFER_SIZE
        );
    }

    bool repeatToUsbDeviceWithEndCheck(
        unsigned char           _ENDPOINT
        , UsbDeviceManager &    _usbDeviceManager
        , Socket &              _socket
        , void *                _buffer
        , int                   _BUFFER_SIZE
        , EndManager &          _endManager
        , int                   _WAITING_MILLISECONDS
    )
    {
        while( 1 ) {
            if( _endManager.isEnd() == true ) {
                return false;
            } else if( _socket.pollIn( _WAITING_MILLISECONDS ) == true ) {
                break;
            }
        }

        return repeatToUsbDevice(
            _ENDPOINT
            , _usbDeviceManager
            , _socket
            , _buffer
            , _BUFFER_SIZE
        );
    }
}

RepeatThread::RepeatThread(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , int                   _SOCKET
    , int                   _WAITING_MILLISECONDS
)
    : thread(
        [
            this
            , &_usbEndpointManager
            , &_usbDeviceManager
            , _SOCKET
            , _WAITING_MILLISECONDS
        ]
        {
            auto    socketUnique = newSocket( _SOCKET );
            auto &  socket = *socketUnique;

            while( 1 ) {
                if( this->endManager.isEnd() == true ) {
                    return;
                } else if( socket.pollIn( _WAITING_MILLISECONDS ) == true ) {
                    break;
                }
            }

            auto    endpoint = static_cast< unsigned char >( 0 );
            if( readEndpoint(
                endpoint
                , socket
            ) != true ) {
                return;
            }

            auto    endpointUnregistererUnique = _usbEndpointManager.registerEndpoint( endpoint );
            if( endpointUnregistererUnique.get() == nullptr ) {
                return;
            }

            const auto  REPEAT_PROC = isUsbEndpointOut( endpoint ) == true
                ? repeatToUsbDeviceWithEndCheck
                : repeatFromUsbDeviceWithEndCheck
            ;

            auto    buffer = Buffer();

            while( 1 ) {
                if( REPEAT_PROC(
                    endpoint
                    , _usbDeviceManager
                    , socket
                    , buffer.data()
                    , BUFFER_SIZE
                    , this->endManager
                    , _WAITING_MILLISECONDS
                ) != true ) {
                    break;
                }
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

bool RepeatThread::isEnd(
)
{
    return this->endManager.isEnd();
}

void RepeatThread::end(
)
{
    this->endManager.end();
}
