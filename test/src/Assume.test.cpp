#include <doctest.h>

#include <cpp/Assume.hpp>

TEST_CASE("Assume")
{
    int i = 42;
    int j = 31;

    CPP_ASSUME(i % 2 == 0);
    CPP_ASSUME(j % 2 == 1);
}
