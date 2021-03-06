#include <doctest.h>

#include <cpp/Constexpr.hpp>

// Define a magic number to return
#define MAGIC_NUMBER 42

CPP_CONSTEXPR int constexpr_func_1()
{
    return MAGIC_NUMBER;
}

CPP_CONSTEXPR_AND_CONST int constexpr_func_2()
{
    return MAGIC_NUMBER;
}

void constexpr_func_3()
{
    CPP_CONSTEXPR_OR(const) int Val = MAGIC_NUMBER;
}

CPP_CONSTEXPR_OR_CONST int constexpr_func_4()
{
    return MAGIC_NUMBER;
}

CPP_CONSTEXPR_OR_INLINE int constexpr_func_5()
{
    return MAGIC_NUMBER;
}

CPP_EXTENDED_CONSTEXPR void constexpr_func_6()
{}

void constexpr_func_7()
{
    CPP_EXTENDED_CONSTEXPR_OR(const) int Val2 = MAGIC_NUMBER;
}

CPP_EXTENDED_CONSTEXPR_OR_CONST void constexpr_func_8()
{}

CPP_EXTENDED_CONSTEXPR_OR_INLINE void constexpr_func_9()
{}

int constexpr_func_10()
{
    auto lam = []() CPP_CONSTEXPR_LAMBDA -> int { return MAGIC_NUMBER; };

    return lam();
}

TEST_CASE("Constexpr")
{
    CHECK_EQ(constexpr_func_1(), MAGIC_NUMBER);
    CHECK_EQ(constexpr_func_2(), MAGIC_NUMBER);
    constexpr_func_3();
    CHECK_EQ(constexpr_func_4(), MAGIC_NUMBER);
    CHECK_EQ(constexpr_func_5(), MAGIC_NUMBER);
    constexpr_func_6();
    constexpr_func_7();
    constexpr_func_8();
    constexpr_func_9();
    CHECK_EQ(constexpr_func_10(), MAGIC_NUMBER);
}
