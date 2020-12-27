#include "sorting_util.h"

namespace algorithms {
namespace sorting {

/**
 * Bubble Sort works by repeatedly swapping the elements if they are in wrong
 * order.
 * @tparam T array's class
 * @tparam N size of array
 * @param array unsorted array
 *
 * Examples:
 *  - Giving an array [5, 2, 3, 1, 4], assuming that we sort the array by
 * ascending order.
 *  - Starting with the first index, we compare the element at current index
 * with the rest. At the end of first loop, we get the smallest element at
 * current index. 0  1  2  3  4 -> array's indexes [5, 2, 3, 1, 4] we compare
 * the first 2 elements then swap 5 and 2 cause 5 > 2 i  j [2, 5, 3, 1, 4] since
 * these elements are in order (2 < 3), we don't swap them i     j [2, 5, 3, 1,
 * 4] swap 2 and 1 i        j [1, 5, 3, 2, 4] don't swap i           j
 *  - Keep looping i to pre-last index and j from i + 1 to the last index.
 *  - After all the loops, array is now sorted.
 */
template <class T, size_t N>
void BubbleSort(T (&array)[N]) {
  for (unsigned int i = 0; i < N - 1; i++)
    for (unsigned int j = i + 1; j < N; j++)
      if (array[i] > array[j]) std::swap(array[i], array[j]);
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[7] = {"c",  "java",  "cpp",        "python",
                            "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithms::sorting::BubbleSort(integers);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithms::sorting::BubbleSort(strings);
  std::cout << "Sorted string array: ";
  algorithms::sorting::PrintArray(
      strings);  // c cpp go java objective-c python swift

  algorithms::sorting::BubbleSort(floats);
  std::cout << "Sorted float array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}