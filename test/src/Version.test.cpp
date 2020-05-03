#include <doctest.h>

#include <cpp/Version.hpp>

TEST_CASE("Version.Attribute")
{
#if __has_cpp_attribute(carries_dependencies)
#endif
#if __has_cpp_attribute(deprecated)
#endif
#if __has_cpp_attribute(fallthrough)
#endif
#if __has_cpp_attribute(likely)
#endif
#if __has_cpp_attribute(unlikely)
#endif
#if __has_cpp_attribute(maybe_unused)
#endif
#if __has_cpp_attribute(no_unique_address)
#endif
#if __has_cpp_attribute(nodiscard)
#endif
#if __has_cpp_attribute(noreturn)
#endif
}

TEST_CASE("Version.CoreLanguage")
{
    int cpp_aggregate_bases      = __cpp_aggregate_bases;
    int cpp_aggregate_nsdmi      = __cpp_aggregate_nsdmi;
    int cpp_aggregate_paren_init = __cpp_aggregate_paren_init;
    int cpp_alias_templates      = __cpp_alias_templates;
    int cpp_aligned_new          = __cpp_aligned_new;
    int cpp_attributes           = __cpp_attributes;
    int cpp_binary_literals      = __cpp_binary_literals;
    int cpp_capture_star_this    = __cpp_capture_star_this;
    int cpp_char8_t              = __cpp_char8_t;
    int cpp_concepts             = __cpp_concepts;
    int cpp_conditional_explicit = __cpp_conditional_explicit;
    int cpp_consteval            = __cpp_consteval;
    int cpp_constexpr            = __cpp_constexpr;
}
