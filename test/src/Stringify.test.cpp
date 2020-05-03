#include <doctest.h>

#include "cpp/Stringify.hpp"
#include <cstring>

TEST_CASE("Stringify")
{
    CHECK_UNARY(std::strcmp(CPP_STRINGIFY(2 + 3), "2 + 3") == 0);
    CHECK_UNARY(std::strcmp(CPP_STRINGIFY(test), "test") == 0);
    CHECK_UNARY(std::strcmp(CPP_STRINGIFY(+-), "+-") == 0);
}
