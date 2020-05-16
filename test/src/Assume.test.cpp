#include <doctest.h>

#include <cpp/Assume.hpp>

#define FIRST_MAGIC_NUMBER 42
#define SECOND_MAGIC_NUMBER 31

TEST_CASE("Assume")
{
    CPP_ASSUME(FIRST_MAGIC_NUMBER % 2 == 0);
    CPP_ASSUME(SECOND_MAGIC_NUMBER % 2 == 1);
}
