#ifndef INCG_CPPBASE_CONSTEXPR_HPP
#define INCG_CPPBASE_CONSTEXPR_HPP

#include "Version.hpp"

// Normal constexpr
#if __cpp_constexpr >= 200704L
#    define CPP_CONSTEXPR constexpr
#    define CPP_CONSTEXPR_OR(alternative) constexpr
#    define CPP_CONSTEXPR_OR_INLINE constexpr
#    define CPP_CONSTEXPR_OR_CONST constexpr
#else
#    define CPP_CONSTEXPR /* Nothing */
#    define CPP_CONSTEXPR_OR(alternative) alternative
#    define CPP_CONSTEXPR_OR_INLINE inline
#    define CPP_CONSTEXPR_OR_CONST const
#endif

// Extended/Relaxed constexpr
#if __cpp_constexpr >= 201304L
#    define CPP_CONSTEXPR_AND_CONST constexpr const
#    define CPP_EXTENDED_CONSTEXPR constexpr
#    define CPP_EXTENDED_CONSTEXPR_OR(alternative) constexpr
#    define CPP_EXTENDED_CONSTEXPR_OR_INLINE constexpr
#    define CPP_EXTENDED_CONSTEXPR_OR_CONST constexpr
#else
#    define CPP_CONSTEXPR_AND_CONST constexpr
#    define CPP_EXTENDED_CONSTEXPR /* Nothing */
#    define CPP_EXTENDED_CONSTEXPR_OR(alternative) alternative
#    define CPP_EXTENDED_CONSTEXPR_OR_INLINE inline
#    define CPP_EXTENDED_CONSTEXPR_OR_CONST const
#endif

// Constexpr lambda
#if __cpp_constexpr >= 201603L
#    define CPP_CONSTEXPR_LAMBDA constexpr
#else
#    define CPP_CONSTEXPR_LAMBDA /* Nothing */
#endif

#endif // INCG_CPPBASE_CONSTEXPR_HPP
