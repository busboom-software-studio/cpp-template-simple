cmake_minimum_required(VERSION 3.9)

project(cpp-template CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/thirdparty/sanitizers-cmake/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(thirdparty/catch)
add_subdirectory(src)
add_subdirectory(test)

