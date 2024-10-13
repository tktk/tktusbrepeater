#include "tktusbrepeater/thread/repeatthread.h"
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
            , &_SOCKET
            , &_WAITING_MILLISECONDS
        ]
        {
            auto    socketUnique = newSocket( _SOCKET );
            auto &  socket = *socketUnique;

            //TODO ポーリング
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
                ? repeatToUsbDevice
                : repeatFromUsbDevice
            ;

            auto    buffer = Buffer();

            while( this->endManager.isEnd() == false ) {
                //TODO ポーリング
                if( REPEAT_PROC(
                    endpoint
                    , _usbDeviceManager
                    , socket
                    , buffer.data()
                    , BUFFER_SIZE
                ) != true ) {
                    break;
                }
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

void RepeatThread::end(
)
{
    this->endManager.end();
}
