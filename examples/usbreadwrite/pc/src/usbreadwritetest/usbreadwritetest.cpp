#include "tktusbrepeater/tktusbrepeater.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <stdexcept>
#include <cstring>

namespace {
    enum {
        ENDPOINT_W = 0x02,
        ENDPOINT_R = 0x81,

        BUFFER_SIZE = 1024,
    };
}

int main(
    int         _argc
    , char **   _argv
)
{
    if( _argc < 2 ) {
        std::cout << "引数が必要" << std::endl;

        return 0;
    }

    const auto  STRING = _argv[ 1 ];

    auto    writerUnique = tktusbrepeater::newWriter(
        "tktusbrepeater"
        , ENDPOINT_W
    );
    if( writerUnique.get() == nullptr ) {
        throw std::runtime_error( "tktusbrepeater::newWriter()が失敗" );
    }

    auto    readerUnique = tktusbrepeater::newReader(
        "tktusbrepeater"
        , ENDPOINT_R
    );
    if( readerUnique.get() == nullptr ) {
        throw std::runtime_error( "tktusbrepeater::newReader()が失敗" );
    }

    while( 1 ) {
        if( writerUnique->write(
            STRING
            , std::strlen( STRING )
        ) < 0 ) {
            throw std::runtime_error( "tktusbrepeater::Writer::write()が失敗" );
        }

        auto    buffer = std::array< char, BUFFER_SIZE >();

        const auto  READ_SIZE = readerUnique->read(
            buffer.data()
            , BUFFER_SIZE
        );
        if( READ_SIZE <= 0 ) {
            throw std::runtime_error( "tktusbrepeater::Reader::read()が失敗" );
        }

        std::cout << READ_SIZE << ":[" << std::setw( READ_SIZE ) << buffer.data() << ']' << std::endl;
    }

    return 0;
}
