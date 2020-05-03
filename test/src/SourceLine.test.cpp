#include <doctest.h>

#include "cpp/SourceLine.hpp"
#include <cstring>

TEST_CASE("SourceLine")
{
    CHECK_UNARY(std::strcmp(CPP_SOURCE_LINE, "8") == 0);
    CHECK_UNARY(std::strcmp(CPP_SOURCE_LINE, "9") == 0);

    // Forcing line
#line 5
    CHECK_UNARY(std::strcmp(CPP_SOURCE_LINE, "5") == 0);
    CHECK_UNARY(std::strcmp(CPP_SOURCE_LINE, "6") == 0);
}
