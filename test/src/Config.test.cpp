#include <doctest.h>

#include <cpp/Config.hpp>
#include <cpp/Stringify.hpp>
#include <cstring>
#include <string>

TEST_CASE("Config")
{
    CHECK_UNARY_FALSE((CPPBASE_VERSION_MAJOR == 0) && (CPPBASE_VERSION_MINOR == 0) &&
                      (CPPBASE_VERSION_PATCH == 0));
    CHECK_NE(CPPBASE_VERSION, 0);
    CHECK_UNARY_FALSE(std::strcmp(CPPBASE_VERSION_STR, "0.0.0") == 0);
    CHECK_UNARY_FALSE(std::strcmp(CPPBASE_VERSION_STR, "..") == 0);

    std::string version = std::string(CPP_STRINGIFY(CPPBASE_VERSION_MAJOR)) + "." +
                          CPP_STRINGIFY(CPPBASE_VERSION_MINOR) + "." +
                          CPP_STRINGIFY(CPPBASE_VERSION_PATCH);
    CHECK_UNARY(CPPBASE_VERSION_STR == version);
}
