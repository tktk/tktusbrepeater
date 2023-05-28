#ifndef TKTUSBREPEATER_LIB_READERWRITER_TEST_H
#define TKTUSBREPEATER_LIB_READERWRITER_TEST_H

#include "tktusbrepeater/lib/impl/socket.h"

struct ReaderWriterImpl
{
    int                 socket;
    SocketImplCloser    socketCloser;
};

#endif  // TKTUSBREPEATER_LIB_READERWRITER_TEST_H
