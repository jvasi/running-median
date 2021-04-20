cmake_minimum_required(VERSION 3.10)
project(RunningMedian)

set(CMAKE_CXX_STANDARD 14)

add_executable(RunningMedian_run main.cpp)

include_directories(RunningMedian_lib)
add_subdirectory(RunningMedian_lib)

target_link_libraries(RunningMedian_run RunningMedian_lib)

add_subdirectory(RunningMedian_tests)
