#include <doctest.h>

#include <cpp/Implicit.hpp>

struct A
{
    CPP_IMPLICIT A(int)
    {}
};

TEST_CASE("Implicit")
{
    A a(3);
}
