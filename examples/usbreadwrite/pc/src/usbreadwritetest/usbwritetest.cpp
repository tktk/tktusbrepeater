#include "tktusbrepeater/tktusbrepeater.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

namespace {
    enum {
        ENDPOINT_W = 0x02,

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

    while( 1 ) {
        if( writerUnique->write(
            STRING
            , std::strlen( STRING )
        ) < 0 ) {
            throw std::runtime_error( "tktusbrepeater::Writer::write()が失敗" );
        }
    }

    return 0;
}
