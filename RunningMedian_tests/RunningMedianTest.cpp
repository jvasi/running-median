/**
 * Running median tests.
 */

#include <algorithm>
#include <list>
#include <sstream>
#include "gtest/gtest.h"
#include "RunningMedianN2.h"
#include "RunningMedianNlogN.h"

/**
 * Quick and easy implementation of median used for verifying the IRunningMedian implementations.
 *
 * @param subarray the vector on which to calculate the getMedian.
 * @return the median of the array.
 */
double calculateMedianOfSubarray(std::vector<double>& subarray);

/**
 * Tests specific running getMedian algorithm implementation with the given input.
 * This method feeds every number from the input, calls the getMedian() method and compares the result with the actual
 * median.
 *
 * @param running_median the specific implementation to test.
 * @param input the input to test with.
 */
void testImplementationWithInput(IRunningMedian& running_median, const std::vector<double>& input);

/**
 * Method testing the given input with all available running median implementations.
 * @param input the input to test with.
 */
void testAllImplementationsWithInput(const std::vector<double>& input);

TEST(RunningMedianSuite, HappyPathInts)
{
	testAllImplementationsWithInput(std::vector<double>{ 1, 2, 3, 4, 5 });
	testAllImplementationsWithInput(std::vector<double>{ 2, 1, 10, 20, 30 });
	testAllImplementationsWithInput(std::vector<double>{ 10, 20, 30, 40, 50 });
}

TEST(RunningMedianSuite, HappyPathDoubles)
{
	testAllImplementationsWithInput(std::vector<double>{ 1.5, 2.5, 3.7, 4.3, 5.1 });
	testAllImplementationsWithInput(std::vector<double>{ 1.4, 2.7, 1.4, 10.2, 20., 30.432 });
	testAllImplementationsWithInput(std::vector<double>{ 10.123, 20.234, 30.345, 40.456, 50.756 });
}

TEST(RunningMedianSuite, HappyPathReversedAndRandomOrder)
{
	testAllImplementationsWithInput(std::vector<double>{ 5, 4, 3, 4, 1 });
	testAllImplementationsWithInput(std::vector<double>{ 51, 41, 31, 41, 11 });
	testAllImplementationsWithInput(std::vector<double>{ 51, 441, 31, 741, 11 });
}

TEST(RunningMedianSuite, NegativeValues)
{
	testAllImplementationsWithInput(std::vector<double>{ -1, -2, -3, -4, -5 });
	testAllImplementationsWithInput(std::vector<double>{ -5, -4, -3, -2, -1 });
	testAllImplementationsWithInput(std::vector<double>{ -5, 4, -3, 2, -1 });
}

TEST(RunningMedianSuite, Zeros)
{
	testAllImplementationsWithInput(std::vector<double>{ 0, 0, 11, 0, -121, 1001 });
	testAllImplementationsWithInput(std::vector<double>{ 0, 0, 0, 0, 0, 0 });
}

TEST(RunningMedianSuite, DuplicateValues)
{
	testAllImplementationsWithInput(std::vector<double>{ 1, 1, 2, 1, 1, 3 });
	testAllImplementationsWithInput(std::vector<double>{ 1, 1, 1, 1, 1, 1 });
}

TEST(RunningMedianSuite, NoElements)
{
	RunningMedianN2 n2;
	RunningMedianN2 n_log_n;

	try
	{
		n2.getMedian();
		ASSERT_FALSE(true) << "Expected exception to be thrown when calling getMedian with no elements.";
	}
	catch (std::runtime_error const& err)
	{
		// Expected
	}

	try
	{
		n_log_n.getMedian();
		ASSERT_FALSE(true) << "Expected exception to be thrown when calling getMedian with no elements.";
	}
	catch (std::runtime_error const& err)
	{
		// Expected
	}
}

TEST(RunningMedianSuite, StressTestWorstCaseScenario)
{
	RunningMedianNlogN running_median;
//     RunningMedianN2 running_median;  // Fails test

	int test_with_elements = 1000000;
	time_t start = time(0);
	for (int i = test_with_elements; i >= 0; i--)
	{
		running_median.addNumber(i);
		running_median.getMedian();

		double seconds_since_start = difftime(time(0), start);
		ASSERT_LE(seconds_since_start, 1) << "Timeout of 1 second exceeded at element " << (test_with_elements - i);
	}
}

void testAllImplementationsWithInput(const std::vector<double>& input)
{
	RunningMedianN2 n2;
	RunningMedianNlogN n_log_n;
	testImplementationWithInput(n2, input);
	testImplementationWithInput(n_log_n, input);
}

void testImplementationWithInput(IRunningMedian& running_median, const std::vector<double>& input)
{
	std::stringstream input_string;
	for (int i = 0; i < input.size(); i++)
	{
		running_median.addNumber(input.at(i));
		input_string << input.at(i) << " ";
		// Calculate the getMedian quick and dirty
		std::vector<double> subarray(input.begin(), input.begin() + i + 1);
		auto expected_median = calculateMedianOfSubarray(subarray);

		ASSERT_EQ(running_median.getMedian(), expected_median) << "Test failed for running_median " <<
															   typeid(running_median).name() << " with input " <<
															   input_string.str();
	}
}

double calculateMedianOfSubarray(std::vector<double>& subarray)
{
	std::sort(subarray.begin(), subarray.end());

	double expectedMedian;
	int middleElement = subarray.size() / 2;
	if (subarray.size() % 2 == 0)
	{
		expectedMedian = (subarray.at(middleElement - 1) + subarray.at(middleElement)) / 2.0;
	}
	else
	{
		expectedMedian = subarray.at(middleElement);
	}

	return expectedMedian;
}