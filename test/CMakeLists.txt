project("CppBase_Tests" CXX)

# Use latest standard available
if    (DEFINED CMAKE_CXX20_STANDARD_COMPILE_OPTION)
    set(LatestCXXStandard 20)
elseif(CMAKE_CXX17_STANDARD_COMPILE_OPTION)
	set(LatestCXXStandard 17)
elseif(CMAKE_CXX14_STANDARD_COMPILE_OPTION)
	set(LatestCXXStandard 14)
elseif(CMAKE_CXX11_STANDARD_COMPILE_OPTION)
	set(LatestCXXStandard 11)
else()
    set(LatestCXXStandard 99)
endif()

file(GLOB TEST_HEADERS
	"include/doctest.h"
	)

file(GLOB TEST_SOURCES
	"src/main.cpp"

	"src/AnonymousName.test.cpp"
	"src/Assume.test.cpp"
	"src/Bit.test.cpp"
	"src/BreakIntoDebugger.test.cpp"
	"src/Compiler.test.cpp"
	"src/Config.test.cpp"
	"src/Constexpr.test.cpp"
	"src/CurrentFunction.test.cpp"
	"src/FunctionLikeMacro.test.cpp"
	"src/Glue.test.cpp"
	"src/Inline.test.cpp"
	"src/Likely.test.cpp"
	"src/NonCopyable.test.cpp"
	"src/NonMoveable.test.cpp"
	"src/OS.test.cpp"
	"src/Stringify.test.cpp"
	"src/SourceLine.test.cpp"
	"src/StreamScopeGuard.test.cpp"
	"src/Version.test.cpp"
	"src/Versioning.test.cpp"
	"src/Warning.test.cpp"
	)

add_executable(${PROJECT_NAME}
	"${TEST_HEADERS}"
	"${TEST_SOURCES}")

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		CppBase::CppBase)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD ${LatestCXXStandard})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

add_test(Unittest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME})
