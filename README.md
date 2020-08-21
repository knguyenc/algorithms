# Data Structures and Algorithms
This repository is a collection of personal implementation of a variety of algorithms using C++. You may find more than one implementation for these problems but using a different algorithm strategies, optimizations or even different programming language.

NOTE: All implementations assume that input always satisfies the requirement.

## Requirements
In able to compile and run project, make sure `clang` or `gcc`, `make` and `cmake` are installed.

CMake is optional, it helps you build and run project easier, but you could manual run each file separately.

Clone repository by `git clone` to your local computer:
```shell script
$ git clone https://github.com/knguyenc/algorithms.git
$ cd algorithms
```

## Build and run
Using CMake:
1. Create __build__ directory:
```shell script
$ mkdir build
$ cd build
```
2. Build project with `cmake` and `make`, remember we are currently in __build__ folder:
```shell script
$ cmake ..
$ make
```
3. All binary files are located inside __build/bin/__ directory.

Using `clang` of `gcc` compiler:
1. Compile your desired file by compiler:
```shell script
$ clang++ ${path_to_source_file} -o ${path_to_output_file}
```
or
```shell script
$ g++ ${path_to_source_file} -o ${path_to_output_file}
```
2. Then run compiled binary file:
```shell script
$ ./${path_to_binary_file}
```
For example:
```shell script
$ clang++ sorting/merge_sort.cc -o build/bin/merge_sort
$ ./build/bin/merge_sort
```

Add `-DCMAKE_BUILD_TYPE=Debug` or `-DCMAKE_BUILD_TYPE=Release` argument to `cmake` command for `Debug`, `Release` respectively.

## Contents
Quick links to implemented data structures and algorithms.

**Data Structures**

- [Linked lists](https://github.com/knguyenc/algorithms/tree/master/data_structures/linked_lists)
  - [Singly linked list](https://github.com/knguyenc/algorithms/blob/master/data_structures/linked_lists/singly_linked_list.h)
  - [Doubly linked list](https://github.com/knguyenc/algorithms/blob/master/data_structures/linked_lists/doubly_linked_list.h)
  - [Circularly linked list](https://github.com/knguyenc/algorithms/blob/master/data_structures/linked_lists/circularly_linked_list.h)
- [Heaps](https://github.com/knguyenc/algorithms/tree/master/data_structures/heaps)
  - [Max heap](https://github.com/knguyenc/algorithms/blob/master/data_structures/heaps/max_heap.h)
  - [Min heap](https://github.com/knguyenc/algorithms/blob/master/data_structures/heaps/min_heap.h)
- [Stacks](https://github.com/knguyenc/algorithms/tree/master/data_structures/stacks)
  - [Stack](https://github.com/knguyenc/algorithms/blob/master/data_structures/stacks/stack.h)
- [Queues](https://github.com/knguyenc/algorithms/tree/master/data_structures/queues)
  - [Queue](https://github.com/knguyenc/algorithms/blob/master/data_structures/queues/queue.h)
  - [Deque](https://github.com/knguyenc/algorithms/blob/master/data_structures/queues/deque.h)
  - [Max priority queue](https://github.com/knguyenc/algorithms/blob/master/data_structures/queues/max_priority_queue.h)
  - [Min priority queue](https://github.com/knguyenc/algorithms/blob/master/data_structures/queues/min_priority_queue.h)

**Sorting Algorithms**

- [Bubble sort](https://github.com/knguyenc/algorithms/blob/master/sorting/bubble_sort.cc)
- [Insertion sort](https://github.com/knguyenc/algorithms/blob/master/sorting/insertion_sort.cc)
- [Merge sort](https://github.com/knguyenc/algorithms/blob/master/sorting/merge_sort.cc)
- [Heap sort](https://github.com/knguyenc/algorithms/blob/master/sorting/heap_sort.cc)
- [Quick sort](https://github.com/knguyenc/algorithms/blob/master/sorting/quick_sort.cc)
- [Counting sort](https://github.com/knguyenc/algorithms/blob/master/sorting/counting_sort.cc)
- [Radix sort](https://github.com/knguyenc/algorithms/blob/master/sorting/radix_sort.cc)
- [Bucket sort](https://github.com/knguyenc/algorithms/blob/master/sorting/bucket_sort.cc)

**Divide and Conquer Algorithms**

- [Maximum subarray](https://github.com/knguyenc/algorithms/blob/master/divide_conquer/maximum_subarray.cc)

**Mathematics Algorithms**

- [Factorial](https://github.com/knguyenc/algorithms/blob/master/mathematics/factorial.cc)
- [Fibonacci](https://github.com/knguyenc/algorithms/blob/master/mathematics/fibonacci.cc)

## Algorithms explanation
TBA

## References
[C++](https://isocpp.org/) \
[CMake](https://cmake.org/documentation/)
