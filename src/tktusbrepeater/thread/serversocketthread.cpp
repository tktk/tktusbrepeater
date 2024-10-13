#include "tktusbrepeater/thread/serversocketthread.h"
#include "tktusbrepeater/thread/repeatthreads.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/socket.h"
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

    void repeatThreadProc(
        UsbEndpointManager &    _usbEndpointManager
        , UsbDeviceManager &    _usbDeviceManager
        , int                   _socket
    )
    {
        auto    socketUnique = newSocket( _socket );
        auto &  socket = *socketUnique;

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

        while( 1 ) {
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

    void startRepeatThread(
        UsbEndpointManager &    _usbEndpointManager
        , UsbDeviceManager &    _usbDeviceManager
        , int                   _socket
    )
    {
        std::thread(
            [
                &_usbEndpointManager
                , &_usbDeviceManager
                , _socket
            ]
            {
                repeatThreadProc(
                    _usbEndpointManager
                    , _usbDeviceManager
                    , _socket
                );
            }
        ).detach();
    }
}

//REMOVEME
ServerSocketThread::ServerSocketThread(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , ServerSocket &        _serverSocket
    , int                   _WAITING_MILLISECONDS
)
    : thread(
        [
            this
            , &_usbEndpointManager
            , &_usbDeviceManager
            , &_serverSocket
            , &_WAITING_MILLISECONDS
        ]
        {
            while( this->endManager.isEnd() == false ) {
                if( _serverSocket.pollIn( _WAITING_MILLISECONDS ) != true ) {
                    continue;
                }

                auto    socket = _serverSocket.accept();

                startRepeatThread(
                    _usbEndpointManager
                    , _usbDeviceManager
                    , socket
                );
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

ServerSocketThread::ServerSocketThread(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , ServerSocket &        _serverSocket
    , RepeatThreads &       _repeatThreads
    , int                   _WAITING_MILLISECONDS
)
    : thread(
        [
            this
            , &_usbEndpointManager
            , &_usbDeviceManager
            , &_serverSocket
            , &_repeatThreads
            , &_WAITING_MILLISECONDS
        ]
        {
            while( this->endManager.isEnd() == false ) {
                if( _serverSocket.pollIn( _WAITING_MILLISECONDS ) != true ) {
                    continue;
                }

                const auto  SOCKET = _serverSocket.accept();

                _repeatThreads.addThread(
                    _usbEndpointManager
                    , _usbDeviceManager
                    , SOCKET
                    , _WAITING_MILLISECONDS
                );
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

void ServerSocketThread::end(
)
{
    this->endManager.end();
}
