#include "tktusbrepeater/commandlineoptions.h"
#include <unistd.h>
#include <string>
#include <iostream>

namespace {
    enum {
        OPTION_KEY_SOCKET_NAME = 's',
        OPTION_KEY_VENDOR_ID = 'v',
        OPTION_KEY_PRODUCT_ID = 'p',
        OPTION_KEY_HELP = 'h',
    };

    bool hexStringToInt(
        int &           _result
        , const char *  _STRING
    )
    {
        auto    index = std::size_t( 0 );

        const auto  RESULT = std::stoi(
            _STRING
            , &index
            , 16
        );
        if( _STRING[ index ] != '\0' ) {
            return false;
        }

        _result = RESULT;

        return true;
    }

    //REMOVEME
    int hexStringToInt(
        const char *    _STRING
    )
    {
        return std::stoi(
            _STRING
            , nullptr
            , 16
        );
    }
}

bool initializeCommandLineOptions(
    CommandLineOptions &    _commandLineOptions
    , const int             _ARGC
    , char * const *        _argv
)
{
    auto    existsSocketName = false;
    auto    existsVendorId = false;
    auto    existsProductId = false;

    auto    illegalVendorId = false;
    auto    illegalProductId = false;

    auto    printHelp = false;

    while( true ) {
        const auto  OPTION_KEY = getopt(
            _ARGC
            , _argv
            , "s:v:p:h"
        );
        if( OPTION_KEY < 0 ) {
            break;
        }

        switch( OPTION_KEY ) {
        case OPTION_KEY_SOCKET_NAME:
            existsSocketName = true;
            _commandLineOptions.socketName = std::string( optarg );
            break;

        case OPTION_KEY_VENDOR_ID:
            existsVendorId = true;
            if( hexStringToInt(
                _commandLineOptions.vendorId
                , optarg
            ) == false ) {
                illegalVendorId = true;
            }
            break;

        case OPTION_KEY_PRODUCT_ID:
            existsProductId = true;
            _commandLineOptions.productId = hexStringToInt( optarg );
            break;

        case OPTION_KEY_HELP:
            printHelp = true;
            goto LOOP_END;
            break;

        default:
/*
            printHelp = true;
*/
            goto LOOP_END;
            break;
        }
    }
    LOOP_END:

    if( printHelp == false ) {
        if( existsSocketName == false ) {
            std::cerr << "ソケット名の指定が必要" << std::endl;

            printHelp = true;
        }
        if( existsVendorId == false ) {
            std::cerr << "ベンダーIDの指定が必要" << std::endl;

            printHelp = true;
        }
        if( existsProductId == false ) {
            std::cerr << "プロダクトIDの指定が必要" << std::endl;

            printHelp = true;
        }
    }

    if( printHelp == false ) {
        if( illegalVendorId == true ) {
            std::cerr << "ベンダーIDが不正" << std::endl;

            printHelp = true;
        }
    }

    if( printHelp == true ) {
        std::cerr << "使い方: " << _argv[ 0 ] << " [オプション]..." << std::endl;
        std::cerr << "オプション:" << std::endl;
        std::cerr << "-s name   : ソケット名" << std::endl;
        std::cerr << "-v id     : 対象USBデバイスのベンダーID(16進数で指定)" << std::endl;
        std::cerr << "-p id     : 対象USBデバイスのプロダクトID(16進数で指定)" << std::endl;
        std::cerr << "-h        : ヘルプ" << std::endl;

        return false;
    }

    return true;
}
