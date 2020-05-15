#include <doctest.h>

#include <cpp/Constexpr.hpp>

CPP_CONSTEXPR int constexpr_func_1()
{
    return 42;
}

CPP_CONSTEXPR_AND_CONST int constexpr_func_2()
{
    return 42;
}

void constexpr_func_3()
{
    CPP_CONSTEXPR_OR(const) int val = 42;
}

CPP_CONSTEXPR_OR_CONST int constexpr_func_4()
{
    return 42;
}

CPP_CONSTEXPR_OR_INLINE int constexpr_func_5()
{
    return 42;
}

CPP_EXTENDED_CONSTEXPR void constexpr_func_6()
{}

void constexpr_func_7()
{
    CPP_EXTENDED_CONSTEXPR_OR(const) int val2 = 42;
}

CPP_EXTENDED_CONSTEXPR_OR_CONST void constexpr_func_8()
{}

CPP_EXTENDED_CONSTEXPR_OR_INLINE void constexpr_func_9()
{}

void constexpr_func_10()
{
    auto lam = []() CPP_CONSTEXPR_LAMBDA -> int { return 42; };

    lam();
}
