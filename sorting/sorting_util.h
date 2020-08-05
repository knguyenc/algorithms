#ifndef ALGORITHMS_SORTING_SORTING_UTIL_H_
#define ALGORITHMS_SORTING_SORTING_UTIL_H_

#include <iostream>

namespace algorithms {
namespace sorting {

template <class T, size_t N>
void PrintArray(const T (&array)[N]) {
  for (T item : array) std::cout << item << " ";
  std::cout << std::endl;
}

}  // namespace sorting
}  // namespace algorithms

#endif  // ALGORITHMS_SORTING_SORTING_UTIL_H_
