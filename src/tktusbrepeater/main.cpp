#include "tktusbrepeater/commandlineoptions.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usb.h"
#include "tktusbrepeater/serversocket.h"
#include "tktusbrepeater/socket.h"
#include "tktusbrepeater/repeat.h"
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

    void usbDeviceManagerThreadProc(
        UsbDeviceManager &  _usbDeviceManager
    )
    {
        while( 1 ) {
            _usbDeviceManager.handleEvents();
        }
    }

    void startUsbDeviceManagerThread(
        UsbDeviceManager &  _usbDeviceManager
    )
    {
        std::thread(
            [
                &_usbDeviceManager
            ]
            {
                usbDeviceManagerThreadProc( _usbDeviceManager );
            }
        ).detach();
    }

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

    void serverSocketThreadProc(
        UsbEndpointManager &    _usbEndpointManager
        , UsbDeviceManager &    _usbDeviceManager
        , ServerSocket &        _serverSocket
    )
    {
        while( 1 ) {
            auto    socket = _serverSocket.accept();

            startRepeatThread(
                _usbEndpointManager
                , _usbDeviceManager
                , socket
            );
        }
    }
}

int main(
    int                 _argc
    , char * const *    _argv
)
{
    auto    options = CommandLineOptions();
    if( initializeCommandLineOptions(
        options
        , _argc
        , _argv
    ) == false ) {
        return 1;
    }

    auto    usbEndpointManager = UsbEndpointManager();

    auto    usbDeviceManagerUnique = newUsbDeviceManager(
        options.vendorId
        , options.productId
    );
    auto &  usbDeviceManager = *usbDeviceManagerUnique;

    startUsbDeviceManagerThread( usbDeviceManager );

    auto    serverSocketUnique = newServerSocket( options.socketName );
    auto &  serverSocket = *serverSocketUnique;

    serverSocketThreadProc(
        usbEndpointManager
        , usbDeviceManager
        , serverSocket
    );

    return 0;
}
