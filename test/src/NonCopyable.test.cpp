#include <doctest.h>

#include <cpp/NonCopyable.hpp>
#include <type_traits>

struct S : cpp::NonCopyable
{};

struct S2 : cpp::NonCopyable
{
    S2() = delete;

    S2(int);
};

TEST_CASE("NonCopyable.inherit")
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
}

struct S3
{
    CPP_NON_COPYABLE(S3);
};

struct S4
{
    S4() = delete;

    S4(int);

    CPP_NON_COPYABLE(S4);
};

TEST_CASE("NonCopyable.Macro")
{
    // S3
    CHECK_UNARY_FALSE(std::is_default_constructible<S3>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S3>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S3>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S3>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S3>::value);

    // S4
    CHECK_UNARY_FALSE(std::is_default_constructible<S4>::value);
    CHECK_UNARY(std::is_constructible<S4, int>::value);

    CHECK_UNARY_FALSE(std::is_copy_constructible<S4>::value);
    CHECK_UNARY_FALSE(std::is_copy_assignable<S4>::value);

    CHECK_UNARY_FALSE(std::is_move_constructible<S4>::value);
    CHECK_UNARY_FALSE(std::is_move_assignable<S4>::value);
}
