#include <doctest.h>

#include <cpp/Compiler.hpp>
// Not my fault MSVC is using codecvt inside fstreams...
#if CPP_COMPILER_IS(CPP_COMPILER_MSVC)
#    define _SILENCE_CXX20_CODECVT_FACETS_DEPRECATION_WARNING
#endif

#include <cpp/StreamScopeGuard.hpp>
#include <cpp/Version.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

#if __cpp_char8_t
#    define CHAR8_T char8_t,
#else
#    define CHAR8_T /* Nothing */
#endif

template <typename Stream>
void TestTemplated(Stream& stream)
{
    SUBCASE("Precision")
    {
        stream.precision(5);
        {
            cpp::StreamScopeGuard<Stream::char_type, Stream::traits_type> guard(stream);
            CHECK_EQ(stream.precision(21), 0);
            CHECK_EQ(stream.precision(), 21);
        }

        CHECK_EQ(stream.precision(), 5);
    }

    SUBCASE("Width")
    {
        stream.width(32);
        {
            cpp::StreamScopeGuard<Stream::char_type, Stream::traits_type> guard(stream);
            CHECK_EQ(stream.width(99), 0);
            CHECK_EQ(stream.width(), 99);
        }
        CHECK_EQ(stream.width(), 32);
    }

    SUBCASE("Flags")
    {
        stream.flags(std::ios_base::oct | std::ios_base::internal);
        {
            cpp::StreamScopeGuard<Stream::char_type, Stream::traits_type> guard(stream);
            CHECK_EQ(stream.flags(std::ios_base::dec),
                     std::ios_base::oct | std::ios_base::internal);
            CHECK_EQ(stream.flags(), std::ios_base::dec);
        }
        CHECK_EQ(stream.flags(), std::ios_base::oct | std::ios_base::internal);
    }
}

TEST_CASE_TEMPLATE("SteamScopeGuard.templated", T, char, unsigned char, signed char,
                   CHAR8_T char16_t, char32_t, wchar_t)
{
    // String streams
    std::basic_stringstream<T> ss;
    TestTemplated(ss);

    std::basic_istringstream<T> ss1;
    TestTemplated(ss1);

    std::basic_ostringstream<T> ss2;
    TestTemplated(ss2);

    // File streams
    std::basic_fstream<T> fs("file");
    TestTemplated(fs);

    std::basic_ifstream<T> fs1("file");
    TestTemplated(fs1);

    std::basic_ofstream<T> fs2("file");
    TestTemplated(fs2);
}

TEST_CASE("StreamScopeGuard.streams")
{
    TestTemplated(std::cout);
    TestTemplated(std::wcout);

    TestTemplated(std::cerr);
    TestTemplated(std::wcerr);

    TestTemplated(std::clog);
    TestTemplated(std::wclog);
}
