#ifndef TKTUSBREPEATER_READERWRITER_TEST_H
#define TKTUSBREPEATER_READERWRITER_TEST_H

#include "tktusbrepeater/impl/socket.h"

struct ReaderWriterImpl
{
    int                 socket;
    SocketImplCloser    socketCloser;
};

#endif  // TKTUSBREPEATER_READERWRITER_TEST_H
