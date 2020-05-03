#include <doctest.h>

#include <cpp/Bit.hpp>
#include <cpp/Constexpr.hpp>
#include <cstdint>

TEST_CASE("bits_test")
{
    static CPP_CONSTEXPR std::uint8_t low_bit = 0;

    static CPP_CONSTEXPR std::uint8_t high_bit = (sizeof(std::uint8_t) * CHAR_BIT) - 1U;

    std::uint8_t val = 0;

    for (std::uint8_t i = low_bit; i <= high_bit; ++i)
    {
        CHECK_UNARY_FALSE(cpp::is_bit_set(val, i));
    }

    CHECK_EQ(cpp::set_bit(val, low_bit), 0b0000'0001);
    CHECK_UNARY(cpp::is_bit_set(val, low_bit));
    CHECK_EQ(cpp::set_bit(val, low_bit), 0b0000'0001);
    CHECK_UNARY(cpp::is_bit_set(val, low_bit));
    CHECK_EQ(cpp::clear_bit(val, low_bit), 0b0000'0000);
    CHECK_UNARY_FALSE(cpp::is_bit_set(val, low_bit));
    CHECK_EQ(cpp::clear_bit(val, low_bit), 0b0000'0000);
    CHECK_UNARY_FALSE(cpp::is_bit_set(val, low_bit));
    CHECK_EQ(cpp::toggle_bit(val, low_bit), 0b000'0001);
    CHECK_UNARY(cpp::is_bit_set(val, low_bit));
    CHECK_EQ(cpp::toggle_bit(val, low_bit), 0b000'0000);
    CHECK_UNARY_FALSE(cpp::is_bit_set(val, low_bit));
}

TEST_CASE("bit_cast")
{
    const std::uint32_t v = cpp::bit_cast<std::uint32_t>(2.0F);
    CHECK_EQ(v, UINT32_C(0x40000000));
}

TEST_CASE("bit.has_single_bit")
{
    CHECK_UNARY_FALSE(cpp::has_single_bit(0U));
    CHECK_UNARY(cpp::has_single_bit(1U));
    CHECK_UNARY(cpp::has_single_bit(2U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(3U));
    CHECK_UNARY(cpp::has_single_bit(4U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(5U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(6U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(7U));
    CHECK_UNARY(cpp::has_single_bit(8U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(9U));
    CHECK_UNARY_FALSE(cpp::has_single_bit(10U));
}
