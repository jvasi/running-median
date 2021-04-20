include(GoogleTest)

# Adding the runningMedianTests target
add_executable(tests RunningMedianTest.cpp)

# linking runningMedianTests with libRunningMedian which will be tested
target_link_libraries(tests libRunningMedian)
target_link_libraries(tests gtest gtest_main)

gtest_discover_tests(tests TEST_PREFIX new:)
add_test(NAME tests COMMAND tests)