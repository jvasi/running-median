cmake_minimum_required(VERSION 3.10)
project(RunningMedian)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(libs/gtest)
