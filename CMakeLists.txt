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

add_subdirectory("CppBase")
