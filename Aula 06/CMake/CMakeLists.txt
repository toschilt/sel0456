cmake_minimum_required(VERSION 3.10)

project(cmake_minimal)

add_executable(main main.c mult_acc.c sqr.c)

target_link_libraries(main pthread)