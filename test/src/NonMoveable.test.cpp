#include <doctest.h>

#include <cpp/NonMoveable.hpp>
#include <type_traits>

struct S : cpp::NonMoveable
{};

struct S2 : cpp::NonMoveable
{
    S2() = delete;

    S2(int);
};

struct S3 : cpp::NonMoveable
{
    S3() = delete;

    S3(int);

    S3(const S3&) = default;
    S3& operator=(const S3&) = default;
};

TEST_CASE("NonMoveable.inherit")
{
    // S
    CHECK_UNARY(std::is_default_constructible<S>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S>::value);

    // S2
    CHECK_UNARY_FALSE(std::is_default_constructible<S2>::value);
    CHECK_UNARY(std::is_constructible<S2, int>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S2>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S2>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S2>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S2>::value);

    // S3
    CHECK_UNARY_FALSE(std::is_default_constructible<S3>::value);
    CHECK_UNARY(std::is_constructible<S3, int>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S3>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S3>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S3>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S3>::value);
}

struct S4
{
    CPP_NON_MOVEABLE(S4);
};

struct S5
{
    S5() = delete;

    S5(int);

    CPP_NON_MOVEABLE(S5);
};

TEST_CASE("NonMoveable.Macro")
{
    // S4
    CHECK_UNARY_FALSE(std::is_default_constructible<S4>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S4>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S4>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S4>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S4>::value);

    // S5
    CHECK_UNARY_FALSE(std::is_default_constructible<S5>::value);
    CHECK_UNARY(std::is_constructible<S5, int>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S5>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S5>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S5>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S5>::value);
}
