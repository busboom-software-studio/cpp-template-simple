# Main program source files and executables

# Define the executable, which has a main() function.
set(EXEC_NAME ${PROJECT_NAME}_p5)
add_executable(${EXEC_NAME} problem5.cpp)
# Link the executable with the library, so all of the sources from $SOURCES
# are linked to the executable file with main in it()
target_link_libraries(${EXEC_NAME} PRIVATE libtreasure)
# Add the include directory, so that the sources from $SOURCES can include without specifying the path
target_include_directories(${EXEC_NAME} PRIVATE ${INCLUDE_DIR} ${LIB_SRC_DIR})

