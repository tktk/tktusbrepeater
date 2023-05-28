#include "tktusbrepeater/usbendpointmanager.h"
#include <mutex>
#include <algorithm>

void UsbEndpointManager::Unregisterer::UnregisterEndpoint::operator()(
    Unregisterer *  _unregistererPtr
) const
{
    auto &  endpointManager = _unregistererPtr->endpointManager;
    auto &  endpoints = endpointManager.endpoints;

    const auto &    ENDPOINT = _unregistererPtr->ENDPOINT;

    auto    lock = std::lock_guard< std::mutex >( endpointManager.endpointsMutex );

    auto    begin = endpoints.begin();
    auto    end = endpoints.end();
    if( begin == end ) {
        return;
    }

    auto    it = std::lower_bound(
        begin
        , end
        , ENDPOINT
    );
    if( *it != ENDPOINT ) {
        return;
    }

    endpoints.erase( it );
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

    auto &  endpoints = this->endpoints;
    auto    begin = endpoints.begin();
    auto    end = endpoints.end();

    auto    it = begin;
    if( begin != end ) {
        it = std::lower_bound(
            begin
            , end
            , _ENDPOINT
        );
        if( it != end && *it == _ENDPOINT ) {
            return nullptr;
        }
    }

    endpoints.insert(
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
