/**
 * Running median algorithm base class.
 */

#ifndef RUNNINGMEDIAN_IRUNNINGMEDIAN_H
#define RUNNINGMEDIAN_IRUNNINGMEDIAN_H

/**
 * Running median algorithm interface.
 */
class IRunningMedian
{
 public:

	/**
	 * Add a number to the collection.
	 * @param number the number to add.
	 */
	virtual void addNumber(const double number) = 0;

	/**
	 * Calculate and return the median of all added numbers.
	 * @return the median.
	 */
	virtual double getMedian() = 0;
};

#endif //RUNNINGMEDIAN_IRUNNINGMEDIAN_H
