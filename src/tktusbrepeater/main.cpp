#include "tktusbrepeater/commandlineoptions.h"

int main(
    int                 _argc
    , char * const *    _argv
)
{
    auto    options = CommandLineOptions();
    if( initializeCommandLineOptions(
        options
        , _argc
        , _argv
    ) == false ) {
        return 1;
    }

    return 0;
}
