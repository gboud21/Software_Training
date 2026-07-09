#Establish the minimum CMake version
#This ensures the following CMake functions are run with a compatible
#version of CMake
cmake_minimum_required(VERSION 3.14)

#This command specifies the project name
project(Cpp11Features VERSION 1.0)
add_compile_options(-g3)

#Set the C++ Standard to C++ 11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)

add_subdirectory(test)
