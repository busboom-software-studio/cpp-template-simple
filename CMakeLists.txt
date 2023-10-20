cmake_minimum_required(VERSION 3.9)

project(cpp-template CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/thirdparty/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(thirdparty/catch)
add_subdirectory(src)
add_subdirectory(test)

# Add the target 'make run' to build and run the tests
add_custom_target(run 
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME} 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Running main program"
)

