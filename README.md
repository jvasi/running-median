### Algorithm implementations overview

Running median implementation. Two algorithms are available:
* With running complexity O(N<sup>2</sup>)
* With running complexity O(Nlog<sub>2</sub>N)

Both algorithms have the same space complexity - O(N). 

The O(N<sup>2</sup>) implementation keeps a sorted array with all added numbers (using merge sort). The median is 
calculated by either taking the middle element (if the array has odd number of elements) or the average of the two 
middle elements (if the array has even number of elements). In the worst case, when numbers are inputted in revered 
sorting order, every operation requires N steps (to insert the element in the beginning of the sorted array).

The O(Nlog<sub>2</sub>N) implementation improves upon the above algorithm by using heaps which can merge element in a 
sorted array in O(log<sub>2</sub>N) time. Since we can't directly find the median in a heap, we keep two heaps - one 
containing all elements to the left of the median (max heap) and one containing all elements to the right (min heap). 
When adding an element we compare it to the current median and add it to the appropriate heap. At all times we need to
ensure that both heaps contain equal number of elements (+/- 1 element) and to do that we may need to transfer an 
element from one heap to the other before inserting the new element. Whichever heap contains more elements is the one 
containing the median. If both heaps have equal number of elements, the median is the average between the top elements 
in both heaps.

All implementations, upon trying to calculate a median of a collection with no elements throw `std::runtime_error`.

### Checkout
To checkout the repository:
```bash
$ git clone --recurse-submodules https://github.com/jvasi/running-median.git
```

### Build

Create a build folder:
```bash
$ mkdir build
```

Run CMake:
```bash
$ cd build
$ cmake ../
```

Run Make:
```bash
$ make
```

### Execution
To run tests:
```bash
$ cd build
$ make test
```

To run an interactive session:
```bash
$ cd build
$ ./src/runningMedian/running_median
```

### Future improvements

The implementation can be further improved by introducing generics for the supported element types of the collection as 
well as the type of the returned median. 
<i>Note that a separate type would be required for the median as, for example, 
inputs of only integers can have floating point median value.</i>

Generics would help to have more memory-conservative instances of this class (e.g. with `short int`) or instances that
support greater range that the currently supported one (e.g. `unsigned long long int`).