#include "tktusbrepeater/test.h"
#include "tktusbrepeater/commandlineoptions.h"
#include <vector>
#include <string>
#include <unistd.h>

namespace {
    class CommandLineOptions_initializeTest : public ::testing::Test
    {
    public:
        void test(
            const std::vector< const char * > & _ARGS
            , const bool                        _EXPECTED
            , CommandLineOptions                _EXPECTED_COMMAND_LINE_OPTIONS
        ) const
        {
            auto    commandLineOptions = CommandLineOptions();

            optind = 1;

            EXPECT_EQ(
                _EXPECTED
                , initializeCommandLineOptions(
                    commandLineOptions
                    , _ARGS.size()
                    , const_cast< char * const * >( _ARGS.data() )
                )
            );

            if( _EXPECTED == true ) {
                EXPECT_EQ( _EXPECTED_COMMAND_LINE_OPTIONS.socketName, commandLineOptions.socketName );
                EXPECT_EQ( _EXPECTED_COMMAND_LINE_OPTIONS.vendorId, commandLineOptions.vendorId );
                EXPECT_EQ( _EXPECTED_COMMAND_LINE_OPTIONS.productId, commandLineOptions.productId );
            }
        }
    };
}

TEST_F(
    CommandLineOptions_initializeTest
    , Standard
)
{
    this->test(
        {
            "tktusbrepeater",
            "-s",
            "SOCKETNAME",
            "-v",
            "12ab",
            "-p",
            "34cd",
        }
        , true
        , CommandLineOptions{
            "SOCKETNAME",
            0x12ab,
            0x34cd,
        }
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Help
)
{
    this->test(
        {
            "tktusbrepeater",
            "-s",
            "SOCKETNAME",
            "-v",
            "12ab",
            "-p",
            "34cd",
            "-h",
        }
        , false
        , CommandLineOptions{}
    );
}

/*
TEST_F(
    CommandLineOptions_initializeTest
    , FailedNotExistsMapFilePath
)
{
    this->test(
        {
            "tktemotejoy",
            "-i",
            "IP",
            "-p",
            "10",
            "DEVICEFILEPATH",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , FailedNotExistsDeviceFilePath
)
{
    this->test(
        {
            "tktemotejoy",
            "-m",
            "MAPFILEPATH",
            "-i",
            "IP",
            "-p",
            "10",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , FailedContainsIllegalOption
)
{
    this->test(
        {
            "tktemotejoy",
            "-m",
            "MAPFILEPATH",
            "-i",
            "IP",
            "-p",
            "10",
            "-X",
            "DEVICEFILEPATH",
        }
        , false
        , CommandLineOptions{}
    );
}
*/
