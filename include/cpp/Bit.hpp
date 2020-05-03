#ifndef INCG_CPPBASE_BIT_HPP
#define INCG_CPPBASE_BIT_HPP

#include "Compiler.hpp"
#include "Config.hpp"
#include "Constexpr.hpp"
#include "Warning.hpp"
#include <climits>
#include <cstdint>
#include <cstring>
#include <memory>
#include <type_traits>

CPP_GCC_SUPPRESS_WARNING_PUSH
CPP_GCC_SUPPRESS_WARNING("-Wconversion")

DETAIL_CPPBASE_BEGIN_NAMESPACE

/*!
     * \brief Sets the bit at position bit of numeric.
     * \param numeric The number to have its bit bit set.
     * \param bit The bit to set in numeric. [0..bits(Numeric))
     * \return A reference to 'numeric'.
     * \warning Do not pass a value in bit that is larger than the amount
     *          of bits in Numeric - 1.
     **/
template <typename Numeric>
CPP_CONSTEXPR Numeric& set_bit(Numeric& numeric, Numeric bit) noexcept
{
    static_assert(std::is_unsigned<Numeric>::value,
                  "Numeric in cpp::set_bit should be an unsigned type.");

    numeric |= static_cast<Numeric>(static_cast<Numeric>(1U) << bit);
    return numeric;
}

/*!
     * \brief Clears the bit bit in numeric.
     * \param numeric The number to have its bit bit cleared.
     * \param bit The bit to clear in numeric. [0..bits(Numeric))
     * \return A reference to 'numeric'.
     * \warning The value in bit must not be larger than the amount of bits in
     *          Numeric - 1.
     **/
template <typename Numeric>
CPP_CONSTEXPR Numeric& clear_bit(Numeric& numeric, Numeric bit) noexcept
{
    static_assert(std::is_unsigned<Numeric>::value,
                  "Numeric in cpp::clear_bit should be an unsigned type.");

    numeric &= static_cast<Numeric>(~(static_cast<Numeric>(1U) << bit));
    return numeric;
}

/*!
     * \brief Toggles the bit bit in numeric.
     * \param numeric The number to have its bit bit toggled.
     * \param bit The bit in numeric to toggle. [0..bits(Numeric))
     * \return A reference to 'numeric'.
     * \warning Do not pass a value in bit that is larger than
     *          the number of bits in Numeric - 1.
     *
     * Toggles the bit that was passed into the parameter bit in the
     * numeric (first parameter). If the bit bit in numeric is 1 it will be
     * 0 after having executed this function. If the bit bit in numeric is 0 it
     * will be 1 after having executed this function.
     **/
template <typename Numeric>
CPP_CONSTEXPR Numeric& toggle_bit(Numeric& numeric, Numeric bit) noexcept
{
    static_assert(std::is_unsigned<Numeric>::value,
                  "Numeric in cpp::toggle_bit should be an unsigned type.");

    numeric ^= static_cast<Numeric>(static_cast<Numeric>(1U) << bit);
    return numeric;
}

/*!
     * \brief Determines whether or not the bit bit in numeric is set.
     * \param numeric The number in which to check the bit bit.
     * \param bit The bit that is to be checked in number. [0..bits(Numeric))
     * \return true if the bit bit in numeric is set; false otherwise.
     * \warning Do not pass a value into the parameter bit that is larger than
     *          the number of bits in Numeric - 1.
     **/
template <typename Numeric>
CPP_CONSTEXPR bool is_bit_set(Numeric numeric, Numeric bit) noexcept
{
    static_assert(std::is_unsigned<Numeric>::value,
                  "Numeric in cpp::is_bit_set should be an unsigned type.");

    return ((numeric & (static_cast<Numeric>(1U) << bit)) != 0);
}

/*!
 * \brief Obtain a value of type To by reinterpreting the object representation
 *        of from.
 * \param from The object to create a binary reinterpretation of as type To.
 * \return The resulting object of type To.
 * \note To and From must have the same size and must both be trivially
 *       copyable.
 *
 * Obtain a value of type To by reinterpreting the object representation of
 * from. Every bit in the value representation of the returned To object is
 * equal to the corresponding bit in the object representation of from. The
 * values of padding bits in the returned To object are unspecified.
 * If there is no value of type To corresponding to the value representation
 * produced, the behavior is undefined. If there are multiple such values, which
 * value is produced is unspecified.
 **/
template <typename To, typename From>
inline To bit_cast(const From& from) noexcept
{
    static_assert(sizeof(To) == sizeof(From), "To and From must have the same byte size.");
    static_assert(alignof(To) == alignof(From),
                  "To and From must have the same alignment requirements.");
    static_assert(std::is_trivial<To>::value, "To is not trivial!");
#if CPP_COMPILER_IS_NOT(CPP_COMPILER_GCC) || CPP_COMPILER_VERSION_IS_ATLEAST(5, 0, 0)
    static_assert(std::is_trivially_copyable<From>::value, "From is not trivially copyable!");
#endif

    std::remove_const_t<To> to;
    std::memcpy(std::addressof(to), std::addressof(from), sizeof(To));
    return to;
}

template <typename Numeric>
CPP_CONSTEXPR bool has_single_bit(Numeric numeric) noexcept
{
    static_assert(std::conditional < std::is_same<Numeric, unsigned char>::value &&
                          std::is_same<Numeric, unsigned short>::value &&
                          std::is_same<Numeric, unsigned int>::value &&
                          std::is_same<Numeric, unsigned long>::value &&
                          std::is_same<Numeric, unsigned long long>::value,
                  std::false_type, std::true_type > ::type::value,
                  "Numeric must be of unsigned inter type");

    return (numeric != 0) && ((numeric & (numeric - 1)) == 0);
}

DETAIL_CPPBASE_END_NAMESPACE

CPP_GCC_SUPPRESS_WARNING_POP

#endif //INCG_CPPBASE_BIT_HPP
