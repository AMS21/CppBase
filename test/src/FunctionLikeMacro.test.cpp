#include <doctest.h>

#include <cpp/FunctionLikeMacro.hpp>

#define FN_TEST()                                                                                  \
    CPP_BEGIN_MACRO                                                                                \
    int i = 3;                                                                                     \
    CPP_END_MACRO

#define FN_TEST_2() CPP_EMPTY_MACRO

TEST_CASE("FunctionLikeMacro")
{
    FN_TEST();

    FN_TEST_2();
}
