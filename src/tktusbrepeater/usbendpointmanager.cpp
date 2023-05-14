#include "tktusbrepeater/usbendpointmanager.h"

void UsbEndpointManager::Unregisterer::UnregisterEndpoint::operator()(
    Unregisterer *  _unregistererPtr
) const
{
    //TODO
}

UsbEndpointManager::Unregisterer::Unregisterer(
    UsbEndpointManager &    _endpointManager
    , unsigned char         _ENDPOINT
)
    : endpointManager( _endpointManager )
    , ENDPOINT( _ENDPOINT )
    , unregistererUnique( this )
{
}

UsbEndpointManager::UnregistererUnique UsbEndpointManager::registerEndpoint(
    unsigned char   _ENDPOINT
)
{
    auto    lock = std::lock_guard< std::mutex >( this->endpointsMutex );

    this->endpoints.insert(
        this->endpoints.begin() + 1
        , _ENDPOINT
    );

    return UnregistererUnique(
        new Unregisterer(
            *this
            , _ENDPOINT
        )
    );
}
