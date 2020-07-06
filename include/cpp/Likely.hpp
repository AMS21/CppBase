#ifndef INCG_CPPBASE_LIKELY_HPP
#define INCG_CPPBASE_LIKELY_HPP

#include "Compiler.hpp"
#include "FunctionLikeMacro.hpp"

#if CPP_COMPILER_IS(CPP_COMPILER_GCC)
#    if CPP_COMPILER_VERSION_IS_ATLEAST(9, 0, 0)
#        define CPP_LIKELY(condition) [[likely]] condition
#        define CPP_UNLIKELY(condition) [[unlikely]] condition
#        define CPP_LIKELY_CASE [[likely]]
#        define CPP_UNLIKELY_CASE [[unlikely]]
#    else
#        define CPP_LIKELY(condition) __builtin_expect(!!(condition), 1)
#        define CPP_UNLIKELY(condition) __builtin_expect(!!(condition), 0)
#        define CPP_LIKELY_CASE   /* Nothing */
#        define CPP_UNLIKELY_CASE /* Nothing */
#    endif
#elif CPP_COMPILER_IS(CPP_COMPILER_CLANG)
#    if __has_builtin(__builtin_expect)
#        define CPP_LIKELY(condition) __builtin_expect(!!(condition), 1)
#        define CPP_UNLIKELY(condition) __builtin_expect(!!(condition), 0)
#    else
#        define CPP_LIKELY(condition) condition
#        define CPP_UNLIKELY(condition) condition
#    endif
#    define CPP_LIKELY_CASE   /* Nothing */
#    define CPP_UNLIKELY_CASE /* Nothing */
#elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 26, 0)
#    define CPP_LIKELY(condition) [[likely]] condition
#    define CPP_UNLIKELY(condition) [[unlikely]] condition
#    define CPP_LIKELY_CASE [[likely]]
#    define CPP_UNLIKELY_CASE [[unlikely]]
#else
#    define CPP_LIKELY(condition) condition
#    define CPP_UNLIKELY(condition) condition
#    define CPP_LIKELY_CASE   /* Nothing */
#    define CPP_UNLIKELY_CASE /* Nothing */
#endif

#endif // INCG_CPPBASE_LIKELY_HPP