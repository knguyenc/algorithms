#include "sorting_util.h"

namespace algorithms {
namespace sorting {

template <size_t N>
void DigitCountingSort(unsigned int (&array)[N], int position) {
  int *output = new int[N];
  int *auxiliary = new int[10];
  for (int i = 0; i < 10 + 1; i++)
    auxiliary[i] = 0;
  for (int element : array)
    auxiliary[(element / position) % 10]++;
  for (int i = 1; i < 10 + 1; i++)
    auxiliary[i] += auxiliary[i - 1];
  for (int i = N - 1; i >= 0; i--) {
    output[auxiliary[(array[i] / position) % 10] - 1] = array[i];
    auxiliary[(array[i] / position) % 10]--;
  }
  for (unsigned int i = 0; i < N; i++)
    array[i] = output[i];
  delete[] auxiliary;
  delete[] output;
}

template <size_t N>
void RadixSort(unsigned int (&array)[N]) {
  unsigned int max_element = *(std::max_element(array, array + N));
  for (int pos = 1; max_element / pos > 0; pos *= 10)
    DigitCountingSort(array, pos);
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  unsigned int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};

  algorithms::sorting::RadixSort(integers);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  return 0;
}