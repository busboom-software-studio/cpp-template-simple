# Main program source files and executables

##
## Add an Executable
##

# Set the name and the source files for the executable
set(EXEC_NAME p5)
add_executable(${EXEC_NAME} problem5.cpp)

# Link the executable with the library, so all of the sources from $SOURCES
# are linked to the executable file with main in it()
target_link_libraries(${EXEC_NAME} PRIVATE libtreasure)
# Add the include directory, so that the sources from $SOURCES can include without specifying the path
target_include_directories(${EXEC_NAME} PRIVATE ${INCLUDE_DIR} ${LIB_SRC_DIR})
## End executable



##
## CMake Targets
##

# Add the target 'make run_${EXEC_NAME}' to build and run the tests
add_custom_target(run_${EXEC_NAME}
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXEC_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        DEPENDS ${EXEC_NAME}iha
        COMMENT "Running main program"
        )

