#include <doctest.h>

#include <cpp/Likely.hpp>

TEST_CASE("Likely")
{
    int i = 5;

    if (CPP_LIKELY(i % 2 == 1))
    {
        CHECK_UNARY(true);
    }

    if (CPP_UNLIKELY(i % 2 == 1))
    {
        CHECK_UNARY(true);
    }

    switch (i)
    {
        CPP_UNLIKELY_CASE case 3 : break;
        CPP_LIKELY_CASE case 5 : CHECK_UNARY(true);
        break;
    }
}
