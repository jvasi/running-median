#include <iostream>
#include <running_median/RunningMedianNlogN.h>

/**
 * Sample usage of the running median implementation.
 * @return 0 if no runtime issues occurred.
 */
int main()
{
	std::cout << "Input numbers (stop with Ctrl+D or invalid input :) ):" << std::endl;

	RunningMedianNlogN running_median;
	std::string line;

	while (std::getline(std::cin, line))
	{
		running_median.addNumber(std::stoi(line));
		std::cout << "Current median: " << running_median.getMedian() << std::endl;
	}

	return 0;
}
