#include <stdexcept>
#include "RunningMedianNlogN.h"

void RunningMedianNlogN::addNumber(double number)
{
	if (maxHeap.size() == 0 && minHeap.size() == 0)
	{
		maxHeap.push(number);
		return;
	}

	auto current_median = getMedian();

	if (number > current_median)
	{
		if (minHeap.size() > maxHeap.size())
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		minHeap.push(number);
	}
	else
	{
		if (maxHeap.size() > minHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		maxHeap.push(number);
	}

}

double RunningMedianNlogN::getMedian()
{
	if (maxHeap.size() == 0 && minHeap.size() == 0)
	{
		throw std::runtime_error("No numbers added yet.");
	}

	if (maxHeap.size() > minHeap.size())
	{
		return maxHeap.top();
	}
	else if (maxHeap.size() < minHeap.size())
	{
		return minHeap.top();
	}
	else
	{
		return (maxHeap.top() + minHeap.top()) / 2.0;
	}
}
