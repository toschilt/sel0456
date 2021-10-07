cmake_minimum_required(VERSION 3.10) # Check CMake Version
project(exerc-1) # Project Name
set(CMAKE_BUILD_TYPE Debug) # Enable GDB
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/) # Set output to /build/
add_executable(sort sort.c)
add_executable(sort-o sort-o.c)