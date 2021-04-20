/**
 * Running median O(NlogN) implementation
 */

#ifndef RUNNINGMEDIAN_RUNNINGMEDIAN_NLOGN_H
#define RUNNINGMEDIAN_RUNNINGMEDIAN_NLOGN_H

#include <queue>
#include "IRunningMedian.h"

/**
 *  Running median O(NlogN) implementation using Min and Max heaps.
 *  Elements lower than the median are kept in the Max heap and elements higher than the median are kept in the Min
 *  heap. Heaps are kept even (+/- 1 element).
 *  Whichever heap has more elements contains the median. If both heaps have the same number of elements, the median is
 *  the average of the top elements in both heaps.
 */
class RunningMedianNlogN : public IRunningMedian
{
 private:
	/**
	 * Heap containing elements to the left of the median.
	 */
	std::priority_queue<double> maxHeap;

	/**
	 * Heap containing elements to the right of the median.
	 */
	std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;

 public:
	/**
	 * Add a number to the collection.
	 * Complexity: O(NlogN)
	 * @param number the number to add.
	 */
	void addNumber(const double number) override;

	/**
	 * Calculate and return the median of all added numbers.
	 * Complexity: O(1)
	 * @return the median.
	 */
	double getMedian() override;
};

#endif //RUNNINGMEDIAN_RUNNINGMEDIAN_NLOGN_H
