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
            , bool                              _EXPECTED
            , CommandLineOptions                _EXPECTED_COMMAND_LINE_OPTIONS
        ) const
        {
            auto    commandLineOptions = CommandLineOptions();

            optind = 1;

            const auto  RESULT = initializeCommandLineOptions(
                commandLineOptions
                , _ARGS.size()
                , const_cast< char * const * >( _ARGS.data() )
            );
            EXPECT_EQ( _EXPECTED, RESULT );

            if( RESULT == true ) {
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

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_notExistsSocketName
)
{
    this->test(
        {
            "tktusbrepeater",
            "-v",
            "12ab",
            "-p",
            "34cd",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_notExistsVendorId
)
{
    this->test(
        {
            "tktusbrepeater",
            "-s",
            "SOCKETNAME",
            "-p",
            "34cd",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_notExistsProductId
)
{
    this->test(
        {
            "tktusbrepeater",
            "-s",
            "SOCKETNAME",
            "-v",
            "12ab",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_illegalVendorId
)
{
    this->test(
        {
            "tktusbrepeater",
            "-s",
            "SOCKETNAME",
            "-v",
            "12abg",
            "-p",
            "34cd",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_illegalProductId
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
            "34cdg",
        }
        , false
        , CommandLineOptions{}
    );
}

TEST_F(
    CommandLineOptions_initializeTest
    , Failed_containsIllegalOption
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
            "-X",
        }
        , false
        , CommandLineOptions{}
    );
}
