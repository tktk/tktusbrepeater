#ifndef TKTUSBREPEATER_COMMANDLINEOPTIONS_H
#define TKTUSBREPEATER_COMMANDLINEOPTIONS_H

#include <string>

struct CommandLineOptions
{
    std::string     socketName;
    int             vendorId;
    int             productId;
};

bool initializeCommandLineOptions(
    CommandLineOptions &
    , const int
    , char * const *
);

#endif  // TKTUSBREPEATER_COMMANDLINEOPTIONS_H
