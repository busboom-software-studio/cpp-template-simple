
# Add source and header files here that are part of the project library,
# not the file that contains main.
set(SOURCES
  "treasure.cpp"
  "treasure.h"
)

# Define the library for the files above.
set(LIB_NAME ${PROJECT_NAME}_lib)
add_library(${LIB_NAME} STATIC ${SOURCES})

set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable, which has a main() function.
add_executable(${PROJECT_NAME} main.cpp)

# Link the executable with the library, so all of the sources from $SOURCES
# are linked to the executable file with main in it()
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})

# Set  compiler options.
target_compile_options(${LIB_NAME} PRIVATE "-Wall")
target_compile_options(${LIB_NAME} PRIVATE "-Wno-vla") # Disable variable length array warning, int foobar[SIZE]
target_compile_options(${LIB_NAME} PRIVATE "-Wextra")
target_compile_options(${LIB_NAME} PRIVATE "-Werror")
target_compile_options(${LIB_NAME} PRIVATE "-pedantic")


