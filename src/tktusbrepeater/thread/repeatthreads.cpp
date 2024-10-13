#include "tktusbrepeater/thread/repeatthreads.h"
#include "tktusbrepeater/thread/repeatthread.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include <algorithm>
#include <utility>

void RepeatThreads::addThread(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , int                   _SOCKET
    , int                   _WAITING_MILLISECONDS
)
{
    const auto  END = this->threadUniques.end();

    const auto  RESULT = std::remove_if(
        this->threadUniques.begin()
        , END
        , [](
            auto &   _threadUnique
        )
        {
            return _threadUnique->isEnd();
        }
    );

    this->threadUniques.erase(
        RESULT
        , END
    );

    auto    repeatThreadUnique = std::unique_ptr< RepeatThread >(
        new RepeatThread(
            _usbEndpointManager
            , _usbDeviceManager
            , _SOCKET
            , _WAITING_MILLISECONDS
        )
    );

    this->threadUniques.push_back( std::move( repeatThreadUnique ) );
}

void RepeatThreads::end(
)
{
    for( auto & threadUnique : this->threadUniques ) {
        threadUnique->end();
    }
}
