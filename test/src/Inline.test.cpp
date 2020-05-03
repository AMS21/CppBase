#include <doctest.h>

#include <cpp/Inline.hpp>

CPP_ALWAYS_INLINE void f()
{}

CPP_NEVER_INLINE void g()
{}

TEST_CASE("Inline")
{
    f();
    g();
}
