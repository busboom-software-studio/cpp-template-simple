
# Add all of the source files for your tests
set(SOURCES
  "hello_test.cpp"
)

find_package(Sanitizers)

set(LIB_NAME ${PROJECT_NAME}_lib)

# This wil be the name of the test progra,
set(TEST_NAME ${PROJECT_NAME}_test)

# Reference the file that holds main() for tjhe test system
add_executable(${TEST_NAME} test_main.cpp ${SOURCES})

add_sanitizers(${TEST_NAME})
target_link_libraries(${TEST_NAME} PRIVATE ${LIB_NAME} catch) # catch is the testing library
target_compile_definitions(${TEST_NAME} PRIVATE CATCH_CONFIG_CONSOLE_WIDTH=60)


target_compile_options(${TEST_NAME} PRIVATE "-Wall")
target_compile_options(${TEST_NAME} PRIVATE "-Wextra")
target_compile_options(${TEST_NAME} PRIVATE "-Werror")
target_compile_options(${TEST_NAME} PRIVATE "-pedantic")

