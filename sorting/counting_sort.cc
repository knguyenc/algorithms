#include "sorting_util.h"

namespace algorithms {
namespace sorting {

template <size_t N>
void CountingSort(unsigned int (&array)[N], unsigned int key) {
  int *output = new int[N];
  int *auxiliary = new int[key + 1];
  for (unsigned int i = 0; i < key + 1; i++)
    auxiliary[i] = 0;
  for (int element : array)
    auxiliary[element]++;
  for (unsigned int i = 1; i < key + 1; i++)
    auxiliary[i] += auxiliary[i - 1];
  for (int i = N - 1; i >= 0; i--) {
    output[auxiliary[array[i]] - 1] = array[i];
    auxiliary[array[i]]--;
  }
  for (unsigned int i = 0; i < N; i++)
    array[i] = output[i];
  delete[] auxiliary;
  delete[] output;
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  unsigned int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};

  algorithms::sorting::CountingSort(integers, *(std::max_element(integers, integers + 11)));
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  return 0;
}