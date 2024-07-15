#include "tktusbrepeater/thread/usbeventhandlingthread.h"
#include "tktusbrepeater/thread/joiner.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include <memory>
#include <ctime>

namespace {
    struct UnlockEventWaiters
    {
        void operator()(
            UsbDeviceManager *  _usbDeviceManagerPtr
        ) const
        {
            _usbDeviceManagerPtr->unlockEventWaiters();
        }
    };

    using UsbEventWaitersUnlocker = std::unique_ptr<
        UsbDeviceManager
        , UnlockEventWaiters
    >;

    auto lockUsbEventWaiters(
        UsbDeviceManager &  _usbDeviceManager
    )
    {
        _usbDeviceManager.lockEventWaiters();

        return UsbEventWaitersUnlocker( &_usbDeviceManager );
    }

    struct UnlockEvents
    {
        void operator()(
            UsbDeviceManager *  _usbDeviceManagerPtr
        ) const
        {
            _usbDeviceManagerPtr->unlockEvents();
        }
    };

    using UsbEventsUnlocker = std::unique_ptr<
        UsbDeviceManager
        , UnlockEvents
    >;

    auto lockUsbEvents(
        UsbDeviceManager &  _usbDeviceManager
    )
    {
        _usbDeviceManager.lockEvents();

        return UsbEventsUnlocker( &_usbDeviceManager );
    }
}

UsbEventHandlingThread::UsbEventHandlingThread(
    UsbDeviceManager &  _usbDeviceManager
    , std::time_t       _WAITING_SECONDS
)
    : usbDeviceManager( _usbDeviceManager )
    , ended( false )
    , thread(
        [
            this
            , &_usbDeviceManager
            , &_WAITING_SECONDS
        ]
        {
            auto    unlocker = lockUsbEvents( _usbDeviceManager );

            while( this->ended == false ) {
                _usbDeviceManager.handleEvents( _WAITING_SECONDS );
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

void UsbEventHandlingThread::end(
)
{
    auto    unlocker = lockUsbEventWaiters( this->usbDeviceManager );

    this->ended = true;
}
