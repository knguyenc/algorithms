#include "sorting_util.h"
#include <vector>

namespace algorithms {
namespace sorting {

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
  for (unsigned int i = 0; i < N; i++)
    sort(buckets[i].begin(), buckets[i].end());
  int index = 0;
  for (unsigned int i = 0; i < N; i++)
    for (unsigned int j = 0; j < buckets[i].size(); j++)
      array[index++] = buckets[i][j];
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