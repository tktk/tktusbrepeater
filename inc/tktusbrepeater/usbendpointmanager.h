#ifndef TKTUSBREPEATER_USBENDPOINTMANAGER_H
#define TKTUSBREPEATER_USBENDPOINTMANAGER_H

#include <memory>
#include <mutex>
#include <vector>

class UsbEndpointManager
{
    std::mutex                      endpointsMutex;
    std::vector< unsigned char >    endpoints;

public:
    struct Unregisterer
    {
        struct UnregisterEndpoint
        {
            void operator()(
                Unregisterer *
            ) const;
        };

        using EndpointUnregistererUnique = std::unique_ptr<
            Unregisterer
            , UnregisterEndpoint
        >;

        UsbEndpointManager &    endpointManager;
        const unsigned char     ENDPOINT;

        EndpointUnregistererUnique  unregistererUnique;

        Unregisterer(
            UsbEndpointManager &
            , unsigned char
        );
    };

    using UnregistererUnique = std::unique_ptr< Unregisterer >;

    UnregistererUnique registerEndpoint(
        unsigned char
    );
};

#endif  // TKTUSBREPEATER_USBENDPOINTMANAGER_H
