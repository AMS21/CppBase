# CppBase top level cmake file
cmake_minimum_required(VERSION 2.8.12)

# Policy
if(${CMAKE_VERSION} VERSION_LESS 3.17)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.17)
endif()

project("CppBase" LANGUAGES CXX)

# Check if CppBase is being used directly or via add_subdirectory, but allow overriding
if(NOT DEFINED CPPBASE_MASTER_PROJECT)
  if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(CPPBASE_MASTER_PROJECT ON)
  else()
    set(CPPBASE_MASTER_PROJECT OFF)
  endif()
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Options
option(CPPBASE_BUILD_TESTS "Whether to build to tests" ${CPPBASE_MASTER_PROJECT})

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CppBase Library
file(
  GLOB
  CPPBASE_HEADERS
  "include/cpp/AnonymousName.hpp"
  "include/cpp/Assume.hpp"
  "include/cpp/Bit.hpp"
  "include/cpp/BreakIntoDebugger.hpp"
  "include/cpp/Compiler.hpp"
  "include/cpp/Config.hpp"
  "include/cpp/Constexpr.hpp"
  "include/cpp/CurrentFunction.hpp"
  "include/cpp/Debug.hpp"
  "include/cpp/FunctionLikeMacro.hpp"
  "include/cpp/Glue.hpp"
  "include/cpp/Inline.hpp"
  "include/cpp/Likely.hpp"
  "include/cpp/NonCopyable.hpp"
  "include/cpp/NonMoveable.hpp"
  "include/cpp/OS.hpp"
  "include/cpp/SourceLine.hpp"
  "include/cpp/StreamScopeGuard.hpp"
  "include/cpp/Stringify.hpp"
  "include/cpp/Version.hpp"
  "include/cpp/Versioning.hpp"
  "include/cpp/Warning.hpp")

# Defined as header only library
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                            "$<INSTALL_INTERFACE:include>" # <prefix>/include
)

if(CPPBASE_MASTER_PROJECT)
  # Hack for IDE's like MSVC see https://stackoverflow.com/a/29214327
  add_custom_target(
    ${PROJECT_NAME}_ide
    SOURCES ${CPPBASE_HEADERS}
    COMMENT "Note is only used so IDEs like MSVC can view the header only library.")
endif()

# Tests
if(${CPPBASE_BUILD_TESTS})
  include(CTest)
  add_subdirectory("test")
endif()
