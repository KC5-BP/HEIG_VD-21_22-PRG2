cmake_minimum_required(VERSION 3.21)
project(PRG2-Exos)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_subdirectory(Chap1-Intro)
add_subdirectory(Chap2-Pointers)
add_subdirectory(Chap3-CompTypes)
add_subdirectory(Chap4-CharString)
add_subdirectory(Chap5-Files)
