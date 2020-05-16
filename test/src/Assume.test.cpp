#include <doctest.h>

#include <cpp/Assume.hpp>

TEST_CASE("Assume")
{
    CPP_ASSUME(FIRST_MAGIC_NUMBER % 2 == 0);
    CPP_ASSUME(SECOND_MAGIC_NUMBER % 2 == 1);
}
