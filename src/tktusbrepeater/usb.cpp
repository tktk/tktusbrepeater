#include "tktusbrepeater/usb.h"

bool isUsbEndpointOut(
    unsigned char   _ENDPOINT
)
{
    return ( _ENDPOINT & 0x80 ) == 0x00;
}
