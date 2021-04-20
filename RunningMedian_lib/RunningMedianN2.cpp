#include <stdexcept>
#include "RunningMedianN2.h"

void RunningMedianN2::addNumber(const double number)
{
	numbers.insert(std::upper_bound(numbers.begin(), numbers.end(), number), number);
}

double RunningMedianN2::getMedian()
{
	if (numbers.size() == 0)
	{
		throw std::runtime_error("No numbers added yet.");
	}

	int mid_element = numbers.size() / 2;
	if (numbers.size() % 2 == 0)
	{
		return (numbers.at(mid_element - 1) + numbers.at(mid_element)) / 2.0;
	}

	return numbers.at(mid_element);
}
