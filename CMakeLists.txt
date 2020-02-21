# CppBase top level cmake file
cmake_minimum_required(VERSION 2.8.12)

# Policy
if(${CMAKE_VERSION} VERSION_LESS 3.16)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.16)
endif()

project("CppBase"
    LANGUAGES CXX)

# Check if CppBase is being used directly or via add_subdirectory, but allow overriding
if (NOT DEFINED CPPBASE_MASTER_PROJECT)
    if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(CPPBASE_MASTER_PROJECT ON)
    else()
        set(CPPBASE_MASTER_PROJECT OFF)
    endif()
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# CppBase Library
file(GLOB CPPBASE_HEADERS
    "include/cpp/SourceLine.hpp"
    "include/cpp/Stringify.hpp"
)

# Defined as header only library
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>" # <prefix>/include
    )

if (CPPBASE_MASTER_PROJECT)
    # Hack for IDE's like MSVC see https://stackoverflow.com/a/29214327
    add_custom_target(${PROJECT_NAME}_ide SOURCES ${CPPBASE_HEADERS})
endif()

# Tests
add_subdirectory("test")
