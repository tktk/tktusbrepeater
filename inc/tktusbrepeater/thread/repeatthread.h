#ifndef TKTUSBREPEATER_THREAD_REPEATTHREAD_H
#define TKTUSBREPEATER_THREAD_REPEATTHREAD_H

#include "tktusbrepeater/thread/endmanager.h"
#include "tktusbrepeater/thread/joiner.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include <thread>

class RepeatThread
{
    EndManager  endManager;

    std::thread     thread;
    ThreadJoiner    threadJoiner;

public:
    RepeatThread(
        UsbEndpointManager &
        , UsbDeviceManager &
        , int
        , int
    );

    void end(
    );
};

#endif  // TKTUSBREPEATER_THREAD_REPEATTHREAD_H
