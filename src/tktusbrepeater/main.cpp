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

    void repeat(
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

    auto    serverSocketUnique = newServerSocket( options.socketName );

    while( 1 ) {
        auto    socket = serverSocketUnique->accept();

        std::thread(
            [
                &usbEndpointManager
                , &usbDeviceManager
                , &socket
            ]
            {
                repeat(
                    usbEndpointManager
                    , usbDeviceManager
                    , socket
                );
            }
        ).detach();
    }

    return 0;
}
