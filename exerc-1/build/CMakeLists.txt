cmake_minimum_required(VERSION 3.10)

# set the project name
project(cmake_minimal)

# add the executable
add_executable(main sort1.c)

target_link_libraries(main pthread)

set(CMAKE_BUILD_TYPE Debug)
