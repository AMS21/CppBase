#ifndef INCG_CPPBASE_STREAM_SCOPE_GUARD_HPP
#define INCG_CPPBASE_STREAM_SCOPE_GUARD_HPP

#include "Config.hpp"
#include <iostream>
#include <sstream>

DETAIL_CPPBASE_BEGIN_NAMESPACE

template <typename CharT, typename Traits>
class StreamScopeGuard
{
public:
    explicit StreamScopeGuard(std::basic_ios<CharT, Traits>& stream) noexcept
        : m_Stream(stream)
        , m_Flags(m_Stream.flags())
        , m_Width(m_Stream.width())
        , m_Precision(m_Stream.precision())
    {
        m_Stream.width(0);
        m_Stream.precision(0);
    }

    ~StreamScopeGuard() noexcept
    {
        m_Stream.flags(m_Flags);
        m_Stream.width(m_Width);
        m_Stream.precision(m_Precision);
    }

private:
    std::basic_ios<CharT, Traits>& m_Stream;
    const std::ios_base::fmtflags  m_Flags;
    const std::streamsize          m_Width;
    const std::streamsize          m_Precision;
};

DETAIL_CPPBASE_END_NAMESPACE

#endif // INCG_CPPBASE_STREAM_SCOPE_GUARD_HPP
