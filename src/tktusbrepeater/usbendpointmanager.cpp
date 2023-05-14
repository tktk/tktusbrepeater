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
    : endpointManager( *static_cast< UsbEndpointManager * >( nullptr ) )
    , ENDPOINT( -1 )
{
    //TODO
}

UsbEndpointManager::UnregistererUnique UsbEndpointManager::registerEndpoint(
    unsigned char   _ENDPOINT
)
{
    //TODO
    return nullptr;
}
