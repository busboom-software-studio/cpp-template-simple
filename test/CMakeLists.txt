cmake_minimum_required(VERSION 3.5)

find_package(Catch2 3 REQUIRED)
include(CTest)
include(Catch)

# Add all of the source files for your tests
set(SOURCES
  "hello_test.cpp"
)


set(LIB_NAME ${PROJECT_NAME}_lib)

# This wil be the name of the test progra,
set(TEST_NAME ${PROJECT_NAME}_test)

find_package(Sanitizers)
add_sanitizers(${TEST_NAME})

# Reference the file that holds main() for tjhe test system
add_executable(${TEST_NAME} test_main.cpp ${SOURCES})


target_link_libraries(${TEST_NAME} PRIVATE ${LIB_NAME} Catch2::Catch2WithMain)
target_compile_definitions(${TEST_NAME} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)


target_compile_options(${TEST_NAME} PRIVATE "-Wall")
target_compile_options(${TEST_NAME} PRIVATE "-Wextra")
target_compile_options(${TEST_NAME} PRIVATE "-Werror")
target_compile_options(${TEST_NAME} PRIVATE "-pedantic")


add_custom_target(test COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${PROJECT_NAME})

enable_testing()

# Discover the tests described in the source files. 
catch_discover_tests(${TEST_NAME})

# Add additional tests, which can use external scripts, alternate arguments, etc
add_test(NAME MyAwesomeTest COMMAND ${TEST_NAME})