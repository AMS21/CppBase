#ifndef INCG_CPPBASE_LIKELY_HPP
#define INCG_CPPBASE_LIKELY_HPP

#include "Compiler.hpp"
#include "FunctionLikeMacro.hpp"

#if CPP_COMPILER_IS(CPP_COMPILER_GCC)
#    if CPP_COMPILER_VERSION_IS_ATLEAST(9, 0, 0)
#        define CPP_LIKELY(condition) [[likely]] condition
#        define CPP_UNLIKELY(condition) [[unlikey]] condition
#    else
#        define CPP_LIKELY(condition) __builtin_expect(!!(condition), 1)
#        define CPP_UNLIKELY(condition) __builtin_expect(!!(condition), 0)
#    endif
#elif CPP_COMPILER_IS(CPP_COMPILER_CLANG)
#    if __has_builtin(__builtin_expect)
#        define CPP_LIKELY(condition) __builtin_expect(!!(condition), 1)
#        define CPP_UNLIKELY(condition) __builtin_expect(!!(condition), 0)
#    else
#        define CPP_LIKELY(condition) condition
#        define CPP_UNLIKELY(condition) condition
#    endif
#elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 26, 0)
#    define CPP_LIKELY(condition) [[likely]] condition
#    define CPP_UNLIKELY(condition) [[unlikely]] condition
#else
#    define CPP_LIKELY(condition) condition
#    define CPP_UNLIKELY(condition) condition
#endif

#endif // INCG_CPPBASE_LIKELY_HPP