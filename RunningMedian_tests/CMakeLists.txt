project(RunningMedian_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# adding the RunningMedian_tests_run target
add_executable(RunningMedian_tests_run RunningMedianTest.cpp)

# linking RunningMedian_tests_run with RunningMedian_lib which will be tested
target_link_libraries(RunningMedian_tests_run RunningMedian_lib)
target_link_libraries(RunningMedian_tests_run gtest gtest_main)
