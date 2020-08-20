/*!
 * \file BreakIntoDebugger.hpp
 * \brief Cross platform macro to break into the debugger
 *
**/
#ifndef INCG_CPPBASE_BREAK_INTO_DEBUGGER_HPP
#define INCG_CPPBASE_BREAK_INTO_DEBUGGER_HPP

#include "Compiler.hpp" // CPP_COMPILER_IS, CPP_COMPILER_MSVC, CPP_COMPILER_MINGW
#include "FunctionLikeMacro.hpp"
#include "OS.hpp" // CPP_OS_IS, CPP_OS_MACOS, CPP_OS_LINUX

#if CPP_OS_IS(CPP_OS_MACOS)
#    define CPP_BREAK_INTO_DEBUGGER() __asm__("int $3\n" : :)
#elif CPP_COMPILER_IS(CPP_COMPILER_MSVC)
#    define CPP_BREAK_INTO_DEBUGGER() __debugbreak()
#elif CPP_COMPILER_IS(CPP_COMPILER_MINGW)
#    include "Warning.hpp"

CPP_GCC_SUPPRESS_WARNING_PUSH
CPP_GCC_SUPPRESS_WARNING("-Wredundant-decls")

extern "C" __declspec(dllimport) void __stdcall DebugBreak();

CPP_GCC_SUPPRESS_WARNING_POP

#    define CPP_BREAK_INTO_DEBUGGER() ::DebugBreak()
#elif CPP_OS_IS(CPP_OS_LINUX)
#    include <csignal>
#    define CPP_BREAK_INTO_DEBUGGER() raise(SIGTRAP)
#else
#    define CPP_BREAK_INTO_DEBUGGER() CPP_EMPTY_MACRO
#endif

/*!
 * \def CPP_BREAK_INTO_DEBUGGER
 * \brief Function like macro for breaking into the debugger
 * \note Currently only supported on MacOS, MSVC, MinGW and Linux on
 *       all other platforms/compilers it simply does nothing.
**/

#endif // INCG_CPPBASE_BREAK_INTO_DEBUGGER_HPP
