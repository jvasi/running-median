/**
 * Running median O(N^2) implementation.
 */

#ifndef RUNNINGMEDIAN_RUNNINGMEDIAN_N2_H
#define RUNNINGMEDIAN_RUNNINGMEDIAN_N2_H

#include <vector>
#include "IRunningMedian.h"

/**
 *  Running median O(N^2) implementation using sorted array of elements.
 */
class RunningMedianN2 : public IRunningMedian
{

 private:
	/**
	 * All numbers to calculate the median over. Kept sorted at all times.
	 */
	std::vector<double> numbers;

 public:
	RunningMedianN2()
	{
	}

	/**
	 * Add a number to the collection.
	 * Complexity: O(N)
	 * @param number the number to add.
	 */
	void addNumber(double number) override;

	/**
	 * Calculate and return the median of all added numbers.
	 * Complexity: O(1)
	 * @return the median.
	 */
	double getMedian() override;
};

#endif //RUNNINGMEDIAN_RUNNINGMEDIAN_N2_H
