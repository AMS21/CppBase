#ifndef INCG_CPPBASE_NON_MOVABLE_HPP
#define INCG_CPPBASE_NON_MOVABLE_HPP

#include "Config.hpp"

DETAIL_CPPBASE_BEGIN_NAMESPACE

class NonMoveable
{
protected:
    NonMoveable() = default;

    ~NonMoveable() = default;

private:
    NonMoveable(const NonMoveable&) = delete;
    NonMoveable(NonMoveable&&)      = delete;

    NonMoveable& operator=(NonMoveable&&) = delete;
    NonMoveable& operator=(const NonMoveable&) = delete;
};

DETAIL_CPPBASE_END_NAMESPACE

/*!
 * \def CPP_NON_MOVEABLE(type_identifier)
 * \brief Macro to be placed in the public section of a type.
 *        Pass the identifier of the type into this macro.
 *        Used to declare a type as non moveable.
**/
#define CPP_NON_MOVEABLE(type_identifier)                                                          \
    type_identifier(const type_identifier&) = delete;                                              \
    type_identifier(type_identifier&&)      = delete;                                              \
    type_identifier& operator=(const type_identifier&) = delete;                                   \
    type_identifier& operator=(type_identifier&&) = delete

#endif // INCG_CPPBASE_NON_MOVABLE_HPP
