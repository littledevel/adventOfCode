cmake_minimum_required(VERSION 3.25)
project(adventOfCode C)

set(CMAKE_C_STANDARD 11)

add_executable(adventOfCode main.c)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)