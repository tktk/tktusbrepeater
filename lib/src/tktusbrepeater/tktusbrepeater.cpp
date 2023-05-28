#include "tktusbrepeater/tktusbrepeater.h"

#define EXPORT __attribute__( ( visibility( "default" ) ) )

namespace {
    struct ReaderWriter
    {
        int socket;
    };

    ReaderWriter * newReaderWriter(
    )
    {
        //TODO
        return nullptr;
    }

    void deleteReaderWriter(
        ReaderWriter *  _readerWriterPtr
    )
    {
        //TODO
/*
        delete _readerWriterPtr;
*/
    }
}

extern "C" {
    EXPORT TktUsbRepeaterReader * tktUsbRepeaterNewReader(
        const char *    _SOCKET_NAME
        , unsigned char _ENDPOINT
    )
    {
        //TODO
        return nullptr;
/*
        return reinterpret_cast< TktUsbRepeaterReader * >(
            newReaderWriter(
                _SOCKET_NAME
                , _ENDPOINT
            )
        );
*/
    }

    EXPORT void tktUsbRepeaterDeleteReader(
        TktUsbRepeaterReader *  _readerPtr
    )
    {
        //TODO
/*
        deleteReaderWriter( reinterpret_cast< ReaderWriter * >( _readerPtr ) );
*/
    }

    EXPORT int tktUsbRepeaterRead(
        TktUsbRepeaterReader *  _readerPtr
        , void *                _buffer
        , int                   _BUFFER_SIZE
    )
    {
        //TODO
        return -1;
    }

    EXPORT TktUsbRepeaterWriter * tktUsbRepeaterNewWriter(
        const char *    _SOCKET_NAME
        , unsigned char _ENDPOINT
    )
    {
        //TODO
        return nullptr;
/*
        return reinterpret_cast< TktUsbRepeaterWriter * >(
            newReaderWriter(
                _SOCKET_NAME
                , _ENDPOINT
            )
        );
*/
    }

    EXPORT void tktUsbRepeaterDeleteWriter(
        TktUsbRepeaterWriter *  _writerPtr
    )
    {
        //TODO
/*
        deleteReaderWriter( reinterpret_cast< ReaderWriter * >( _writerPtr ) );
*/
    }

    EXPORT int tktUsbRepeaterWrite(
        TktUsbRepeaterWriter *  _writerPtr
        , const void *          _DATA
        , int                   _DATA_SIZE
    )
    {
        //TODO
        return -1;
    }
}
