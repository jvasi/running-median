cmake_minimum_required(VERSION 3.10)
project(RunningMedian)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(RunningMedian_run ${SOURCE_FILES})

include_directories(RunningMedian_lib)
add_subdirectory(RunningMedian_lib)

target_link_libraries(RunningMedian_run RunningMedian_lib)

add_subdirectory(Google_tests)
