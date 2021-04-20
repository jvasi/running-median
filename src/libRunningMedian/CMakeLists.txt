add_library(libRunningMedian
        RunningMedianN2.cpp
        RunningMedianNlogN.cpp
        ../include/running_median/RunningMedianN2.h
        ../include/running_median/RunningMedianNlogN.h
        ../include/running_median/IRunningMedian.h)

# This adds the current source directory as an include directory for consumers of our library.
# If we have generated headers we would also add CMAKE_CURRENT_BINARY_DIR.
target_include_directories(libRunningMedian PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/../include
        $<INSTALL_INTERFACE:include>
        )