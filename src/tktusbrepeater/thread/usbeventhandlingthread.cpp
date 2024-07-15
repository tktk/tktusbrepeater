#include "tktusbrepeater/thread/usbeventhandlingthread.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include <ctime>

UsbEventHandlingThread::UsbEventHandlingThread(
    UsbDeviceManager &  _usbDeviceManager
    , std::time_t       _WAITING_SECONDS
)
    : thread(
        [
            this
            , &_usbDeviceManager
            , &_WAITING_SECONDS
        ]
        {
            while( this->endManager.isEnd() == false ) {
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
    this->endManager.end();
}
