#include "tktusbrepeater/usbendpointmanager.h"
#include <algorithm>

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

    auto    begin = this->endpoints.begin();
    auto    end = this->endpoints.end();
    auto    it = begin;

    if( begin != end ) {
        it = std::lower_bound(
            this->endpoints.begin()
            , this->endpoints.end()
            , _ENDPOINT
        );
        if( *it == _ENDPOINT ) {
            return nullptr;
        }
    }

    this->endpoints.insert(
        it
        , _ENDPOINT
    );

    return UnregistererUnique(
        new Unregisterer(
            *this
            , _ENDPOINT
        )
    );
}
