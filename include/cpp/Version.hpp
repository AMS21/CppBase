#ifndef INCG_CPPBASE_VERSION_HPP
#define INCG_CPPBASE_VERSION_HPP

// Links to status pages
// GCC:   https://gcc.gnu.org/projects/cxx-status.html
// Clang: https://clang.llvm.org/cxx_status.html

#include "Compiler.hpp"
#include "Glue.hpp"

// Include standard version header if available
#ifdef __has_include
#    if __has_include(<version>)
#        include <version>
#    endif
#endif

// Attributes
#ifndef __has_cpp_attribute
#    define __has_cpp_attribute(attribute_token) CPP_GLUE(DETAIL_CPP_ATTRIBUTE_, attribute_token)

// carries_dependencies (https://wg21.link/N2643 http://wg21.link/N2761.pdf)
// Note GCC-4.8+ and Clang-3.3+ support but don't implement carries_dependencies
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define DETAIL_CPP_ATTRIBUTE_carries_dependencies 200809L
#    else
#        define DETAIL_CPP_ATTRIBUTE_carries_dependencies 0L
#    endif

// deprecated (https://wg21.link/N3760)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 9, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 4, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define DETAIL_CPP_ATTRIBUTE_deprecated 201309L
#    else
#        define DETAIL_CPP_ATTRIBUTE_deprecated 0L
#    endif

// fallthrough (https://wg21.link/P0188R1)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 9, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 10, 0)
#        define DETAIL_CPP_ATTRIBUTE_fallthrough 201603L
#    else
#        define DETAIL_CPP_ATTRIBUTE_fallthrough 0L
#    endif

// likely & unlikely (https://wg21.link/P0479R5)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 9, 0, 0)
#        define DETAIL_CPP_ATTRIBUTE_likely 201803L
#        define DETAIL_CPP_ATTRIBUTE_unlikely 201803L
#    else
#        define DETAIL_CPP_ATTRIBUTE_likely 0L
#        define DETAIL_CPP_ATTRIBUTE_unlikely 0L
#    endif

// maybe_unused (https://wg21.link/P0212R1)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 9, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 11, 0)
#        define DETAIL_CPP_ATTRIBUTE_maybe_unused 201603L
#    else
#        define DETAIL_CPP_ATTRIBUTE_maybe_unused 0L
#    endif

// no_unique_address (https://wg21.link/P0840R2)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 9, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 9, 0, 0)
#        define DETAIL_CPP_ATTRIBUTE_no_unique_address 201803L
#    else
#        define DETAIL_CPP_ATTRIBUTE_no_unique_address 0L
#    endif

// nodiscard (https://wg21.link/P0189R1 https://wg21.link/P1301R4)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 10, 0, 0) ||                                     \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 9, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 25, 0)
#        define DETAIL_CPP_ATTRIBUTE_nodiscard 201907L // nodiscard with message
#    elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                    \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 9, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 11, 0)
#        define DETAIL_CPP_ATTRIBUTE_nodiscard 201603L // nodiscard without message
#    else
#        define DETAIL_CPP_ATTRIBUTE_nodiscard 0L
#    endif

// noreturn (https://wg21.link/N2761)
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 8, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 3, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define DETAIL_CPP_ATTRIBUTE_noreturn 200809L
#    else
#        define DETAIL_CPP_ATTRIBUTE_noreturn 0L
#    endif

#endif // !__has_cpp_attribute

// Core Language features

// __cpp_aggregate_bases (https://wg21.link/P0017R1)
#ifndef __cpp_aggregate_bases
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 9, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 14, 0)
#        define __cpp_aggregate_bases 201603L
#    else
#        define __cpp_aggregate_bases 0L
#    endif
#endif // !__cpp_aggregate_bases

// __cpp_aggregate_nsdmi
#ifndef __cpp_aggregate_nsdmi
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 5, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 3, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 10, 0)
#        define __cpp_aggregate_nsdmi 201304L
#    else
#        define __cpp_aggregate_nsdmi 0L
#    endif
#endif // !__cpp_aggregate_nsdmi

// __cpp_aggregate_paren_init
#ifndef __cpp_aggregate_paren_init
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 10, 0, 0)
#        define __cpp_aggregate_paren_init 201902L
#    else
#        define __cpp_aggregate_paren_init 0L
#    endif
#endif // !__cpp_aggregate_paren_init

// __cpp_alias_templates
#ifndef __cpp_alias_templates
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 7, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 18, 0, 0)
#        define __cpp_alias_templates 200704L
#    else
#        define __cpp_alias_templates 0L
#    endif
#endif // !__cpp_alias_templates

// __cpp_aligned_new
#ifndef __cpp_aligned_new
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 4, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 12, 0)
#        define __cpp_aligned_new 201606L
#    else
#        define __cpp_aligned_new 0L
#    endif
#endif // !__cpp_aligned_new

// __cpp_attributes
#ifndef __cpp_attributes
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 8, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 3, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define __cpp_attributes 200809L
#    else
#        define __cpp_attributes 0L
#    endif
#endif // !__cpp_attributes

// __cpp_binary_literals
#ifndef __cpp_binary_literals
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 9, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 4, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define __cpp_binary_literals 201304L
#    else
#        define __cpp_binary_literals 0L
#    endif
#endif // !__cpp_binary_literals

// __cpp_capture_star_this
#ifndef __cpp_capture_star_this
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 9, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 11, 0)
#        define __cpp_capture_star_this 201603L
#    else
#        define __cpp_capture_star_this 0L
#    endif
#endif // !__cpp_capture_star_this

// __cpp_char8_t
#ifndef __cpp_char8_t
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 9, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 7, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 22, 0)
#        define __cpp_char8_t 201811L
#    else
#        define __cpp_char8_t 0L
#    endif
#endif // !__cpp_char8_t

// __cpp_concepts
#ifndef __cpp_concepts
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 10, 0, 0) ||                                     \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 10, 0, 0)
#        define __cpp_concepts 201907L
#    else
#        define __cpp_concepts 0L
#    endif
#endif // !__cpp_concepts

// __cpp_conditional_explicit
#ifndef __cpp_conditional_explicit
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 9, 0, 0) ||                                      \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 9, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 24, 0)
#        define __cpp_conditional_explicit 201806L
#    else
#        define __cpp_conditional_explicit 0L
#    endif
#endif // !__cpp_conditional_explicit

// __cpp_consteval
#ifndef __cpp_consteval
#    define __cpp_consteval 0L
#endif // !__cpp_consteval

// __cpp_constexpr
#ifndef __cpp_constexpr
#    if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 10, 0, 0) ||                                     \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 10, 0, 0)
#        define __cpp_constexpr 201907L
#    elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 7, 0, 0) ||                                    \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 5, 0, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 11, 0)
#        define __cpp_constexpr 201603L
#    elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 5, 0, 0) ||                                    \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 4, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 10, 0)
#        define __cpp_constexpr 201304L
#    elif CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 6, 0) ||                                    \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 3, 1, 0) ||                                \
            CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
#        define __cpp_constexpr 200704L
#    else
#        define __cpp_constexpr 0L
#    endif
#endif // !__cpp_constexpr

// Library features

#endif // INCG_CPPBASE_VERSION_HPP
