cmake_minimum_required(VERSION 3.21)
project(PRG2-Exos)

set(CMAKE_C_STANDARD 17)
# Add -lm flag to include the math lib. to the compilation
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -Wpedantic -lm")

add_subdirectory(corr/Chap1-Intro)
add_subdirectory(corr/Chap2-Pointers)
add_subdirectory(corr/Chap3-CompTypes)
add_subdirectory(corr/Chap4-CharString)
add_subdirectory(corr/Chap5-Files)

add_subdirectory(archivesTEs)
