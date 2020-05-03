#ifndef INCG_CPPBASE_NON_COPYABLE_HPP
#define INCG_CPPBASE_NON_COPYABLE_HPP

#include "Config.hpp"

DETAIL_CPPBASE_BEGIN_NAMESPACE

class NonCopyable
{
protected:
    NonCopyable() = default;

    ~NonCopyable() = default;

private:
    NonCopyable(const NonCopyable&) = delete;

    NonCopyable& operator=(const NonCopyable&) = delete;
};

DETAIL_CPPBASE_END_NAMESPACE

/*!
 * \def CPP_NON_COPYABLE(type_identifier)
 * \brief Macro to be placed in the public section of a type.
 *        Pass the identifier of the type into this macro.
 *        Used to declare a type as non copyable.
**/
#define CPP_NON_COPYABLE(type_identifier)                                                          \
    type_identifier(const type_identifier&) = delete;                                              \
    type_identifier& operator=(const type_identifier&) = delete

#endif // INCG_CPPBASE_NON_COPYABLE_HPP
