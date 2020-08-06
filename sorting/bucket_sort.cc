#include "sorting_util.h"
#include <vector>

namespace algorithms {
namespace sorting {

template <class T, size_t N>
bool CheckBucketSortInputArray(T (&array)[N]) {
  if (*(typeid(T).name()) != 'f' && *(typeid(T).name()) != 'd') {
    std::cout << "Only accept non-negative floating point number array." << std::endl;
    return false;
  }
  for (T element : array) {
    if (element < 0 || element >= 1) {
      std::cout << "Only accept non-negative floating point number array in range [0, 1)." << std::endl;
      return false;
    }
  }
  return true;
}

template <class T, size_t N>
void BucketSort(T (&array)[N]) {
  if (!CheckBucketSortInputArray(array)) return;
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
  float floats[8] = {0.52f, 0.44f, 0.68f, 0.95f, 1.0f, 0.12f, 0.32f, 0.59f};

  algorithms::sorting::BucketSort(floats);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}