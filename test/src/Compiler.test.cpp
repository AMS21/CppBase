#include <doctest.h>

#include <cpp/Compiler.hpp>
#include <cstring>

TEST_CASE("Compiler")
{
    CHECK_NE(CPP_COMPILER, CPP_COMPILER_UNKNOWN);
    CHECK_UNARY(std::strcmp(CPP_COMPILER_NAME, "Unknown") != 0);
    CHECK_UNARY_FALSE((CPP_COMPILER_MAJOR == 0) && (CPP_COMPILER_MINOR == 0) &&
                      (CPP_COMPILER_PATCH == 0));
    CHECK_NE(CPP_COMPILER_VERSION, 0);
}
