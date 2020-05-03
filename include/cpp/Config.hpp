#ifndef INCG_CPPBASE_CONFIG_HPP
#define INCG_CPPBASE_CONFIG_HPP

#include "Compiler.hpp"
#include "Glue.hpp"
#include "Stringify.hpp"
#include "Versioning.hpp"

#define CPPBASE_VERSION_MAJOR 0
#define CPPBASE_VERSION_MINOR 1
#define CPPBASE_VERSION_PATCH 0

#define CPPBASE_VERSION                                                                            \
    CPP_VERSION_CREATE(CPPBASE_VERSION_MAJOR, CPPBASE_VERSION_MINOR, CPPBASE_VERSION_PATCH)

#define CPPBASE_VERSION_STR                                                                        \
    CPP_STRINGIFY(CPPBASE_VERSION_MAJOR)                                                           \
    "." CPP_STRINGIFY(CPPBASE_VERSION_MINOR) "." CPP_STRINGIFY(CPPBASE_VERSION_PATCH)

#if CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_GCC, 4, 4, 0) ||                                          \
        CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_CLANG, 2, 9, 0) ||                                    \
        CPP_COMPILER_IS_ATLEAST(CPP_COMPILER_MSVC, 19, 0, 0)
// clang-format off
#    define DETAIL_CPPBASE_BEGIN_NAMESPACE                                                         \
        namespace cpp { inline namespace CPP_GLUE6(v_, CPPBASE_VERSION_MAJOR, _,     \
        CPPBASE_VERSION_MINOR, _, CPPBASE_VERSION_PATCH) {
#    define DETAIL_CPPBASE_END_NAMESPACE } }
#else
#    define DETAIL_CPPBASE_BEGIN_NAMESPACE namespace cpp {
#    define DETAIL_CPPBASE_END_NAMESPACE }
// clang-format on
#endif

#endif // INCG_CPPBASE_CONFIG_HPP
