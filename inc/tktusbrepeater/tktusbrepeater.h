#ifndef TKTUSBREPEATER_TKTUSBREPEATER_H
#define TKTUSBREPEATER_TKTUSBREPEATER_H

#include <stddef.h>

#ifdef  __cplusplus
extern "C" {
#endif  // __cplusplus

    typedef struct TktUsbRepeaterReader TktUsbRepeaterReader;

    TktUsbRepeaterReader * tktUsbRepeaterNewReader(
        const char *
        , size_t
        , unsigned char
    );

    void tktUsbRepeaterDeleteReader(
        TktUsbRepeaterReader *
    );

    int tktUsbRepeaterRead(
        TktUsbRepeaterReader *
        , void *
        , int
    );

    typedef struct TktUsbRepeaterWriter TktUsbRepeaterWriter;

    TktUsbRepeaterWriter * tktUsbRepeaterNewWriter(
        const char *
        , size_t
        , unsigned char
    );

    void tktUsbRepeaterDeleteWriter(
        TktUsbRepeaterWriter *
    );

    int tktUsbRepeaterWrite(
        TktUsbRepeaterWriter *
        , const void *
        , int
    );

#ifdef  __cplusplus
}
#endif  // __cplusplus

#ifdef  __cplusplus

#include <memory>
#include <string>

namespace tktusbrepeater {
    class Reader
    {
    public:
        Reader(
        ) = delete;

        ~Reader(
        ) = delete;

        int read(
            void *  _buffer
            , int   _BUFFER_SIZE
        )
        {
            return tktUsbRepeaterRead(
                reinterpret_cast< TktUsbRepeaterReader * >( this )
                , _buffer
                , _BUFFER_SIZE
            );
        }
    };

    struct DeleteReader
    {
        void operator()(
            Reader *    _readerPtr
        ) const
        {
            tktUsbRepeaterDeleteReader( reinterpret_cast< TktUsbRepeaterReader * >( _readerPtr ) );
        }
    };

    using ReaderUnique = std::unique_ptr<
        Reader
        , DeleteReader
    >;

    inline auto newReader(
        const std::string & _SOCKET_NAME
        , unsigned char     _ENDPOINT
    )
    {
        return ReaderUnique(
            reinterpret_cast< Reader * >(
                tktUsbRepeaterNewReader(
                    _SOCKET_NAME.c_str()
                    , _SOCKET_NAME.size()
                    , _ENDPOINT
                )
            )
        );
    }

    class Writer
    {
    public:
        Writer(
        ) = delete;

        ~Writer(
        ) = delete;

        int write(
            const void *    _DATA
            , int           _DATA_SIZE
        )
        {
            return tktUsbRepeaterWrite(
                reinterpret_cast< TktUsbRepeaterWriter * >( this )
                , _DATA
                , _DATA_SIZE
            );
        }
    };

    struct DeleteWriter
    {
        void operator()(
            Writer *    _writerPtr
        ) const
        {
            tktUsbRepeaterDeleteWriter( reinterpret_cast< TktUsbRepeaterWriter * >( _writerPtr ) );
        }
    };

    using WriterUnique = std::unique_ptr<
        Writer
        , DeleteWriter
    >;

    inline auto newWriter(
        const std::string & _SOCKET_NAME
        , unsigned char     _ENDPOINT
    )
    {
        return WriterUnique(
            reinterpret_cast< Writer * >(
                tktUsbRepeaterNewWriter(
                    _SOCKET_NAME.c_str()
                    , _SOCKET_NAME.size()
                    , _ENDPOINT
                )
            )
        );
    }
}

#endif  // __cplusplus

#endif  // TKTUSBREPEATER_TKTUSBREPEATER_H
