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

// Workaround for MSVC-STL bug in versions prior to 2019/19.20
// See https://stackoverflow.com/questions/32055357/visual-studio-c-2015-stdcodecvt-with-char16-t-or-char32-t
#if CPP_COMPILER_IS_BELOW(CPP_COMPILER_MSVC, 19, 20, 0)
// Apparently Microsoft forgot to define a symbol for codecvt.
// Works with /MT only
#    include <locale>

#    if (!_DLL) && (_MSC_VER >= 1900 /* VS 2015*/) && (_MSC_VER <= 1911 /* VS 2017 */)
std::locale::id std::codecvt<char16_t, char, _Mbstatet>::id;
#    endif
#endif

template <typename Stream>
void TestTemplated(Stream& stream)
{
    SUBCASE("Precision")
    {
        stream.precision(5);
        {
            cpp::StreamScopeGuard<typename Stream::char_type, typename Stream::traits_type> guard(
                    stream);
            CHECK_EQ(stream.precision(21), 0);
            CHECK_EQ(stream.precision(), 21);
        }

        CHECK_EQ(stream.precision(), 5);
    }

    SUBCASE("Width")
    {
        stream.width(32);
        {
            cpp::StreamScopeGuard<typename Stream::char_type, typename Stream::traits_type> guard(
                    stream);
            CHECK_EQ(stream.width(99), 0);
            CHECK_EQ(stream.width(), 99);
        }
        CHECK_EQ(stream.width(), 32);
    }

    SUBCASE("Flags")
    {
        stream.flags(std::ios_base::oct | std::ios_base::internal);
        {
            cpp::StreamScopeGuard<typename Stream::char_type, typename Stream::traits_type> guard(
                    stream);
            CHECK_EQ(stream.flags(std::ios_base::dec),
                     std::ios_base::oct | std::ios_base::internal);
            CHECK_EQ(stream.flags(), std::ios_base::dec);
        }
        CHECK_EQ(stream.flags(), std::ios_base::oct | std::ios_base::internal);
    }
}

template <typename T>
void TestTemplatedTop()
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

TEST_CASE("SteamScopeGuard.templated")
{
    TestTemplatedTop<char>();
    TestTemplatedTop<unsigned char>();
    TestTemplatedTop<signed char>();
#if __cpp_char8_t
    TestTemplatedTop<char8_t>();
#endif
    TestTemplatedTop<char16_t>();
    TestTemplatedTop<char32_t>();
    TestTemplatedTop<wchar_t>();
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
