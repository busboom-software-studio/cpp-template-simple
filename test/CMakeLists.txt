cmake_minimum_required(VERSION 3.5)



# Add all of the source files for your tests
set(SOURCES
  "treasure_tests.cpp"
)

set(LIB_NAME ${PROJECT_NAME}_lib)

# This wil be the name of the test program,
set(TEST_NAME ${PROJECT_NAME}_test)


# Reference the file that hods main() for tjhe test system
add_executable(${TEST_NAME} test_main.cpp ${SOURCES})


target_link_libraries(${TEST_NAME} PRIVATE ${LIB_NAME} Catch2::Catch2WithMain)
target_compile_definitions(${TEST_NAME} PRIVATE )


add_custom_target(test 
  COMMAND ${CMAKE_CTEST_COMMAND} --build-target all -V --output-on-failure
  DEPENDS ${PROJECT_NAME})


# Download the Catch2 distribution
Include(FetchContent)
set(FETCHCONTENT_BASE_DIR "${CMAKE_BINARY_DIR}/build/_deps" CACHE STRING "Base directory for FetchContent downloads" FORCE)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

include(Catch)

enable_testing()

# Discover the tests described in the source files. 
catch_discover_tests(${TEST_NAME})

# Add additional tests, which can use external scripts, alternate arguments, etc
add_test(NAME ExtraTest COMMAND ${TEST_NAME})

# Run the test program, with a dependency on building it. 
add_custom_target(build_test 
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME} 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build and test"
)

target_compile_options(${TEST_NAME} PRIVATE "-Wno-vla") # Disable variable length array warning, int foobar[SIZE]
target_compile_options(${LIB_NAME} PRIVATE "-Wno-unused-parameter") # The instructors required a func def with unused params.

target_compile_options(${TEST_NAME} PRIVATE "-Wall")
target_compile_options(${TEST_NAME} PRIVATE "-Wextra")
target_compile_options(${TEST_NAME} PRIVATE "-Werror")
#target_compile_options(${TEST_NAME} PRIVATE "-pedantic")
