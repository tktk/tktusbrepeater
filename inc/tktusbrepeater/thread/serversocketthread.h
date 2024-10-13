#ifndef TKTUSBREPEATER_THREAD_SERVERSOCKETTHREAD_H
#define TKTUSBREPEATER_THREAD_SERVERSOCKETTHREAD_H

#include "tktusbrepeater/thread/repeatthreads.h"
#include "tktusbrepeater/thread/endmanager.h"
#include "tktusbrepeater/thread/joiner.h"
#include "tktusbrepeater/usbdevicemanager.h"
#include "tktusbrepeater/usbendpointmanager.h"
#include "tktusbrepeater/serversocket.h"
#include <thread>

class ServerSocketThread
{
    EndManager  endManager;

    std::thread     thread;
    ThreadJoiner    threadJoiner;

public:
    ServerSocketThread(
        UsbEndpointManager &
        , UsbDeviceManager &
        , ServerSocket &
        , RepeatThreads &
        , int
    );

    void end(
    );
};

#endif  // TKTUSBREPEATER_THREAD_SERVERSOCKETTHREAD_H
