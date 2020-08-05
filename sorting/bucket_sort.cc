#include "sorting_util.h"
#include <vector>

namespace algorithms {
namespace sorting {

template <size_t N>
void BucketSort(float (&array)[N]) {
  std::vector<float> buckets[N];
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
  float floats[8] = {0.52f, 0.44f, 0.68f, 0.95f, 0.7f, 0.12f, 0.32f, 0.59f};

  algorithms::sorting::BucketSort(floats);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}