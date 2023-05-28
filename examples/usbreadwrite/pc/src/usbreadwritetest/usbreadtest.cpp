#include "tktusbrepeater/tktusbrepeater.h"
#include <iostream>
#include <iomanip>
#include <array>
#include <stdexcept>

namespace {
    enum {
        ENDPOINT_R = 0x81,

        BUFFER_SIZE = 1024,
    };
}

int main(
)
{
    auto    readerUnique = tktusbrepeater::newReader(
        "tktusbrepeater"
        , ENDPOINT_R
    );
    if( readerUnique.get() == nullptr ) {
        throw std::runtime_error( "tktusbrepeater::newReader()が失敗" );
    }

    while( 1 ) {
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
