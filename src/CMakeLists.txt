# Main program source files and executables

# Define the executable, which has a main() function.
add_executable(${PROJECT_NAME}_p5 problem5.cpp)

# Link the executable with the library, so all of the sources from $SOURCES
# are linked to the executable file with main in it()
target_link_libraries(${PROJECT_NAME}_p5 PRIVATE libtreasure)
