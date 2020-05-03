#include <doctest.h>

#include "cpp/Glue.hpp"
#include <cstring>

TEST_CASE("Glue")
{
    int CPP_GLUE(int_, var) = 3;

    int_var = 5;
    CHECK_EQ(int_var, 5);
}
