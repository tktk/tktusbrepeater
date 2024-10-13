#include "tktusbrepeater/thread/usbeventhandlingthread.h"
#include "tktusbrepeater/thread/serversocketthread.h"
#include "tktusbrepeater/commandlineoptions.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/serversocket.h"
#include <memory>

namespace {
    enum {
        WAITING_SECONDS = 1,
        WAITING_MILLISECONDS = WAITING_SECONDS * 1000,
    };
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

    auto    usbEventHandlingThreadUnique = std::unique_ptr< UsbEventHandlingThread >(
        new UsbEventHandlingThread(
            usbDeviceManager
            , WAITING_SECONDS
        )
    );

    auto    serverSocketUnique = newServerSocket( options.socketName );
    auto &  serverSocket = *serverSocketUnique;

    auto    serverSocketThreadUnique = std::unique_ptr< ServerSocketThread >(
        new ServerSocketThread(
            usbEndpointManager
            , usbDeviceManager
            , serverSocket
            , WAITING_MILLISECONDS
        )
    );

    return 0;
}
