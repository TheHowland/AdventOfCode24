cmake_minimum_required(VERSION 3.22)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)


add_executable(AdventOfCode Day3.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -march=x86-64")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -march=x86-64")
