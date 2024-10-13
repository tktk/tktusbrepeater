#ifndef TKTUSBREPEATER_THREAD_REPEATTHREADS_H
#define TKTUSBREPEATER_THREAD_REPEATTHREADS_H

#include "tktusbrepeater/thread/repeatthread.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include <vector>
#include <memory>

class RepeatThreads
{
    std::vector< std::unique_ptr< RepeatThread > >  threadUniques;

public:
    void addThread(
        UsbEndpointManager &
        , UsbDeviceManager &
        , int
        , int
    );

    void end(
    );
};

#endif  // TKTUSBREPEATER_THREAD_REPEATTHREADS_H
