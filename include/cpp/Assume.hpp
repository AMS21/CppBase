/*!
 * \file Assume.hpp
 * \brief Exports a macro for compiler optimizations.
**/
#ifndef INCG_CPPBASE_ASSUME_HPP
#define INCG_CPPBASE_ASSUME_HPP

#include "Compiler.hpp"
#include "FunctionLikeMacro.hpp"

#if CPP_COMPILER_IS(CPP_COMPILER_MSVC)
#    define CPP_ASSUME(condition) __assume(condition)
#elif CPP_COMPILER_IS(CPP_COMPILER_CLANG)
#    if __has_builtin(__builtin_assume)
#        define CPP_ASSUME(condition) __builtin_assume(condition)
#    else
#        define CPP_ASSUME(condition) CPP_EMPTY_MACRO /* Nothing */
#    endif
#elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 5, 3)
// clang-format off
#   define CPP_ASSUME(condition) if (condition){} else __builtin_unreachable()
// clang-format on
#else
#    define CPP_ASSUME(condition) CPP_EMPTY_MACRO /* Nothing */
#endif

#endif // INCG_CPPBASE_ASSUME_HPP
