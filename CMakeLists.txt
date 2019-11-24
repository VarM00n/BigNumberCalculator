cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator main.cpp Calculator.cpp Calculator.h Number.cpp Number.h)