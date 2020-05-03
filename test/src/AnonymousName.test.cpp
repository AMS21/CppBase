#include <doctest.h>

#include "cpp/AnonymousName.hpp"

TEST_CASE("AnonymouseName")
{
    int CPP_ANONYMOUS_NAME(var);
    int CPP_ANONYMOUS_NAME(var);
    int CPP_ANONYMOUS_NAME(var);

    CHECK_UNARY(true);
}
