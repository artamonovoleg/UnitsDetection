cmake_minimum_required(VERSION 3.20)
project(TestTask)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(subs/glm)
include_directories(subs/glm)

add_executable(TestTask main.cpp)
