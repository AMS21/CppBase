project("CppBase_Tests" CXX)

file(GLOB TEST_HEADERS
	"include/doctest.h"
	)

file(GLOB TEST_SOURCES
	"src/main.cpp"
	)

add_executable(${PROJECT_NAME}
	"${TEST_HEADERS}"
	"${TEST_SOURCES}")

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		CppBase::CppBase)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING")

add_test(Unittest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME})
