#include "tktusbrepeater/commandlineoptions.h"
#include <unistd.h>
#include <string>

namespace {
    enum {
        OPTION_KEY_SOCKET_NAME = 's',
        OPTION_KEY_VENDOR_ID = 'v',
        OPTION_KEY_PRODUCT_ID = 'p',
        OPTION_KEY_HELP = 'h',
    };

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
            _commandLineOptions.socketName = std::string( optarg );
            break;

        case OPTION_KEY_VENDOR_ID:
            _commandLineOptions.vendorId = hexStringToInt( optarg );
            break;

        case OPTION_KEY_PRODUCT_ID:
            _commandLineOptions.productId = hexStringToInt( optarg );
            break;

/*
        case OPTION_KEY_HELP:
            printHelp = true;
            goto LOOP_END;
            break;
*/

        default:
/*
            printHelp = true;
*/
            goto LOOP_END;
            break;
        }
    }
    LOOP_END:

    return true;
}
