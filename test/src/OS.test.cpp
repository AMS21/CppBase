#include <doctest.h>

#include <cpp/OS.hpp>
#include <cstring>

TEST_CASE("OS")
{
    CHECK_NE(CPP_OS, CPP_OS_UNKNOWN);
    CHECK_NE(CPP_OS_FAMILY, CPP_OS_FAMILY_UNKNOWN);
    CHECK_UNARY_FALSE(std::strcmp(CPP_OS_NAME, "Unknown") == 0);
}
