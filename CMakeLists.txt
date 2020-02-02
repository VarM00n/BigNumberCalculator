cmake_minimum_required(VERSION 3.14)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator_run main.cpp)

include_directories(Calculator_lib)
add_subdirectory(Calculator_lib)

target_link_libraries(Calculator_run Calculator_lib)

add_subdirectory(Google_tests)