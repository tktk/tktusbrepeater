#ifndef TKTUSBREPEATER_THREAD_USBEVENTHANDLINGTHREAD_H
#define TKTUSBREPEATER_THREAD_USBEVENTHANDLINGTHREAD_H

#include "tktusbrepeater/thread/endmanager.h"
#include "tktusbrepeater/thread/joiner.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include <thread>
#include <ctime>

class UsbEventHandlingThread
{
    EndManager  endManager;

    std::thread     thread;
    ThreadJoiner    threadJoiner;

public:
    UsbEventHandlingThread(
        UsbDeviceManager &
        , std::time_t
    );

    void end(
    );
};

#endif  // TKTUSBREPEATER_THREAD_USBEVENTHANDLINGTHREAD_H
