/*!
 * \file OS.hpp
 * \brief Defines macros to determine the operating system being used.
 *
**/
#ifndef INCG_CPPBASE_OS_HPP
#define INCG_CPPBASE_OS_HPP

// clang-format off

/*!
 * \def CPP_OS_WINDOWS
 * \brief CPP_OS will be defined as this if compiling on Windows.
**/
#define CPP_OS_WINDOWS (0x0001) /* meaningless number */

/*!
 * \def CPP_OS_MACOS
 * \brief CPP_OS will be defined as this if compiling on MacOs.
**/
#define CPP_OS_MACOS   (0x0002) /* meaningless number */

/*!
 * \def CPP_OS_LINUX
 * \brief CPP_OS will be defined as this if compiling on Linux.
**/
#define CPP_OS_LINUX   (0x0003) /* meaningless number */

/*!
 * \def CPP_OS_ANDROID
 * \brief CPP_OS will be defined as this if compiling on Android.
**/
#define CPP_OS_ANDROID (0x0004) /* meaningless number */

/*!
 * \def CPP_OS_FREEBSD
 * \brief CPP_OS will be defined as this if compiling on FreeBSD.
**/
#define CPP_OS_FREEBSD (0x0005) /* meaningless number */

/*!
 * \def CPP_OS_SOLARIS
 * \brief CPP_OS will be defined as this if compiling on Solaris.
**/
#define CPP_OS_SOLARIS (0x0006) /* meaningless number */

/*!
 * \def CPP_OS_IOS
 * \brief CPP_OS will be defined as this if compiling on IOS.
**/
#define CPP_OS_IOS     (0x0007) /* meaningless number */

/*!
 * \def CPP_OS_OPENBSD
 * \brief CPP_OS will be defined as this if compiling on OpenBSD.
**/
#define CPP_OS_OPENBSD (0x0008) /* meaningless number */

/*!
 * \def CPP_OS_UNKNOWN
 * \brief CPP_OS will be defined as this if the operating system could not be determined.
**/
#define CPP_OS_UNKNOWN (0xFFFF) /* meaningless number */

#define CPP_OS_FAMILY_DOS     (0x0001) /* meaningless number */
#define CPP_OS_FAMILY_UNIX    (0x0002) /* meaningless number */
#define CPP_OS_FAMILY_BSD     (0x0003) /* meaningless number */
#define CPP_OS_FAMILY_UNKNOWN (0xFFFF) /* meaningless number */
// clang-format on

#if defined(_WIN32)
#    define CPP_OS CPP_OS_WINDOWS
#    define CPP_OS_NAME "Windows"
#    define CPP_OS_FAMILY CPP_OS_FAMILY_DOS
#elif defined(__APPLE__) && defined(__MACH__)
// Apple platform, see which one it is
#    include "TargetConditionals.h"
#    if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#        define CPP_OS CPP_OS_IOS
#        define CPP_OS_NAME "IPhone"
#    elif TARGET_OS_MAC
#        define CPP_OS CPP_OS_MACOS
#        define CPP_OS_NAME "MacOS"
#    else
#        warning "Unknown MacOS based operating system"
#        define CPP_OS CPP_OS_UNKNOWN
#        define CPP_OS_NAME "Unknown"
#    endif
#    define CPP_OS_FAMILY CPP_OS_FAMILY_UNIX
#elif defined(__unix__) || defined(__unix) // Unix based OS
#    if defined(__ANDROID__)
#        define CPP_OS CPP_OS_ANDROID
#        define CPP_OS_NAME "Android"
#        define CPP_OS_FAMILY CPP_OS_FAMILY_UNIX
#    elif defined(__linux__)
#        define CPP_OS CPP_OS_LINUX
#        define CPP_OS_NAME "Linux"
#        define CPP_OS_FAMILY CPP_OS_FAMILY_UNIX
#    elif defined(__FreeBSD__)
#        define CPP_OS CPP_OS_FREEBSD
#        define CPP_OS_NAME "FreeBSD"
#        define CPP_OS_FAMILY CPP_OS_FAMILY_BSD
#    elif defined(__OpenBSD__)
#        define CPP_OS CPP_OS_OPENBSD
#        define CPP_OS_NAME "OpenBSD"
#        define CPP_OS_FAMILY CPP_OS_FAMILY_BSD
#    else
#        define CPP_OS CPP_OS_UNKNOWN
#        define CPP_OS_NAME "Unknown"
#        warning "Unknown Unix based operating system"
#        define CPP_OS_FAMILY CPP_OS_FAMILY_UNIX
#    endif
#elif defined(__sun) && defined(__SVR4)
#    define CPP_OS CPP_OS_SOLARIS
#    define CPP_OS_FAMILY CPP_OS_FAMILY_UNIX
#    define CPP_OS_NAME "Solaris"
#else
#    define CPP_OS CPP_OS_UNKNOWN
#    define CPP_OS_FAMILY CPP_OS_FAMILY_UNKNOWN
#    define CPP_OS_NAME "Unknown"
#    warning "Operating system could not be detected"
#endif

#define CPP_OS_IS(os) (CPP_OS == (os))

#define CPP_OS_IS_NOT(os) (CPP_OS != (os))

#define CPP_OS_FAMILY_IS(family) (CPP_OS_FAMILY == (family))

#define CPP_OS_FAMILY_IS_NOT(family) (CPP_OS_FAMILY != (family))

#endif // INCG_CPPBASE_OS_HPP
