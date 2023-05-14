#ifndef TKTUSBREPEATER_USBENDPOINTMANAGER_TEST_H
#define TKTUSBREPEATER_USBENDPOINTMANAGER_TEST_H

#include <mutex>
#include <vector>

struct UsbEndpointManagerImpl
{
    std::mutex                      endpointsMutex;
    std::vector< unsigned char >    endpoints;
};

#endif  // TKTUSBREPEATER_USBENDPOINTMANAGER_TEST_H
