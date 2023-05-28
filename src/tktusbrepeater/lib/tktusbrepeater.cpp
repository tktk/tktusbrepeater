#include "tktusbrepeater/tktusbrepeater.h"
#include "tktusbrepeater/lib/impl/socket.h"
#include "tktusbrepeater/usb.h"
#include <memory>

#define EXPORT __attribute__( ( visibility( "default" ) ) )

namespace {
    struct ReaderWriter
    {
        int                 socket;
        SocketImplCloser    socketCloser;

        ReaderWriter(
            int _socket
        )
            : socket( _socket )
            , socketCloser( &( this->socket ) )
        {
        }
    };

    using ReaderWriterUnique = std::unique_ptr< ReaderWriter >;

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
        if( isUsbEndpointOut( _ENDPOINT ) != false ) {
            return nullptr;
        }

        auto    socket = initializeSocketImpl();
        if( socket < 0 ) {
            return nullptr;
        }

        auto    readerWriterUnique = ReaderWriterUnique( new ReaderWriter( socket ) );

        if( connectSocketImpl(
            socket
            , _SOCKET_NAME
        ) != true ) {
            return nullptr;
        }

        if( writeSocketImpl(
            socket
            , &_ENDPOINT
            , 1
        ) < 0 ) {
            return nullptr;
        }

        return reinterpret_cast< TktUsbRepeaterReader * >( readerWriterUnique.release() );
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
