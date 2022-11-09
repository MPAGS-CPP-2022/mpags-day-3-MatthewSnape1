#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

#include <vector>

TEST_CASE("Testing Command line,[alphanumeric]"){
    ProgramSettings test_set;

    SECTION("Testing file input/output"){
        processCommandLine(std::vector<std::string>{"","-i" , "in_test.txt","-o","out_test.txt"},test_set);
        REQUIRE(test_set.inputFile == std::string{"in_test.txt"});
        REQUIRE(test_set.outputFile == std::string{"out_test.txt"});
        REQUIRE(test_set.cipherKey == "5");
    }

    SECTION("Testing decrypt"){
    processCommandLine(std::vector<std::string>{"","--decrypt"},test_set);
    REQUIRE(test_set.mode == CipherMode::decrypt);
    }

    SECTION("Testing encrypt"){
    processCommandLine(std::vector<std::string>{"","--encrypt"},test_set);
    REQUIRE(test_set.mode == CipherMode::encrypt);
    }

    SECTION("Testing help/version/key"){
    processCommandLine(std::vector<std::string>{"","-h","--version","-k","5"},test_set);
    REQUIRE(test_set.helpRequested == true);
    REQUIRE(test_set.versionRequested == true);
    REQUIRE(test_set.cipherKey == "5");

    }

    SECTION("Additional help test"){
    processCommandLine(std::vector<std::string>{"","--help"},test_set);
    REQUIRE(test_set.helpRequested == true);

    }

}