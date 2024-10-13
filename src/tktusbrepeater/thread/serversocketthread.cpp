#include "tktusbrepeater/thread/serversocketthread.h"
#include "tktusbrepeater/thread/repeatthreads.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/serversocket.h"
#include <thread>

ServerSocketThread::ServerSocketThread(
    UsbEndpointManager &    _usbEndpointManager
    , UsbDeviceManager &    _usbDeviceManager
    , ServerSocket &        _serverSocket
    , RepeatThreads &       _repeatThreads
    , int                   _WAITING_MILLISECONDS
)
    : thread(
        [
            this
            , &_usbEndpointManager
            , &_usbDeviceManager
            , &_serverSocket
            , &_repeatThreads
            , &_WAITING_MILLISECONDS
        ]
        {
            while( this->endManager.isEnd() == false ) {
                if( _serverSocket.pollIn( _WAITING_MILLISECONDS ) != true ) {
                    continue;
                }

                const auto  SOCKET = _serverSocket.accept();

                _repeatThreads.addThread(
                    _usbEndpointManager
                    , _usbDeviceManager
                    , SOCKET
                    , _WAITING_MILLISECONDS
                );
            }
        }
    )
    , threadJoiner( &( this->thread ) )
{
}

void ServerSocketThread::end(
)
{
    this->endManager.end();
}
