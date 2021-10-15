cmake_minimum_required(VERSION 3.10)

# Definindo o nome do projeto cmake
project(exerc-1)

# Incluindo debug na compilação
set(CMAKE_BUILD_TYPE Debug)

# Adiciona o executável do código em C
add_executable(sort sort.c)

# Adiciona o executável do código em C++
add_executable(sort-o sort-o.cpp)