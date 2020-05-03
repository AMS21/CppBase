#include <doctest.h>

#include <cpp/Likely.hpp>

TEST_CASE("Likely")
{
    int i = 5;

    if (CPP_LIKELY(i % 2 == 1))
    {
        CHECK_UNARY(true);
    }

    if (CPP_UNLIKELY(i % 2) == 0)
    {
        CHECK_UNARY(false);
    }
}
