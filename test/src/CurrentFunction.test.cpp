#include <doctest.h>

#include "cpp/CurrentFunction.hpp"

TEST_CASE("CurrentFunction")
{
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay)
    const char* func_name = CPP_CURRENT_FUNCTION;
}
