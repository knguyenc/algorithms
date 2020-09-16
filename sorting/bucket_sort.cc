#include "sorting_util.h"
#include <vector>
#include <cassert>

namespace algorithms {
namespace sorting {

/**
 * Bubble Sort is mainly useful when sorting a large set of floating point numbers
 * which are in range [0, 1). It works by distributing elements to buckets,
 * then sorts each bucket and finally concatenates all sorted buckets.
 * @tparam T T array's class
 * @tparam N size of array
 * @param array unsorted array (non-negative floating point number array in range [0, 1))
 *
 * Examples:
 *  - Giving an array [0.52, 0.12, 0.86, 0.29, 0.46, 0.4, 0.18, 0.6], 10 buckets and
 *  assuming that we sort the array by ascending order.
 *  - Distributing all the elements to corresponding buckets by multiplying the element
 *  and buckets' slots. Each bucket is a linked list.
 *    [0.52, 0.12, 0.86, 0.29, 0.46, 0.4, 0.18, 0.6] -> array
 *    [[], [], [], [], [], [], [], [], [], []] -> buckets
 *    [0 []
 *     1 [] -> [0.12] -> [0.18]   0.12 * 10 = 1.2, 0.18 * 10 = 1.8
 *     2 [] -> [0.29]   0.29 * 10 = 2.9
 *     3 []
 *     4 [] -> [0.46] -> [0.4]   0.46 * 10 = 4.6, 0.4 * 10 = 4.0
 *     5 [] -> [0.52]   0.52 * 10 = 5.2
 *     6 [] -> [0.6]
 *     7 []
 *     8 [] -> [0.86]   0.86 * 10 = 8.6
 *     9 []
 *     ]
 *  - We sort each bucket using insertion sort.
 *    [[], [0.12, 0.18], [0.29], [], [0.4, 0.46], [0.52], [0.6], [], [0.86], []]
 *  - Concatenating all non-empty buckets, array is now sorted.
 */
template <class T, size_t N>
void BucketSort(T (&array)[N]) {
  if (!std::is_same<T, float>::value && !std::is_same<T, double>::value)
    throw std::runtime_error("Only accept floating point number array.");
  for (T element : array)
    if (element < 0 || element >= 1)
      throw std::runtime_error("Only accept non-negative floating point number array in range [0, 1).");

  std::vector<T> buckets[N];
  for (unsigned int i = 0; i < N; i++) {
    int bucket_index = N * array[i];
    buckets[bucket_index].push_back(array[i]);
  }

  int index = 0;
  for (unsigned int i = 0; i < N; i++) {
    sort(buckets[i].begin(), buckets[i].end());
    for (unsigned int j = 0; j < buckets[i].size(); j++)
      array[index++] = buckets[i][j];
  }
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  float floats[8] = {0.52f, 0.44f, 0.68f, 0.95f, 0.1f, 0.12f, 0.32f, 0.59f};
  double doubles[8] = {0.52, 0.44, 0.68, 0.95, 0.1, 0.12, 0.32, 0.59};

  algorithms::sorting::BucketSort(floats);
  std::cout << "Sorted float array: ";
  algorithms::sorting::PrintArray(floats);  // 0.1 0.12 0.32 0.44 0.52 0.59 0.68 0.95

  algorithms::sorting::BucketSort(doubles);
  std::cout << "Sorted double array: ";
  algorithms::sorting::PrintArray(doubles);  // 0.1 0.12 0.32 0.44 0.52 0.59 0.68 0.95

  return 0;
}