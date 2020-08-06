#include "sorting_util.h"

namespace algorithms {
namespace sorting {

template <class T, size_t N>
bool CheckCountingSortInputArray(T (&array)[N]) {
  if (*(typeid(T).name()) != 'j' && *(typeid(T).name()) != 'h') {
    std::cout << "Only accept non-negative integer or character array." << std::endl;
    return false;
  }
  return true;
}

template <class T, size_t N>
void CountingSort(T (&array)[N], T key) {
  if (!CheckCountingSortInputArray(array)) return;
  T *output = new T[N];
  T *auxiliary = new T[key + 1];
  for (unsigned int i = 0; i < key + 1; i++)
    auxiliary[i] = 0;
  for (T element : array)
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
  unsigned char chars[8] = {'d', 'g', 'a', 'b', 'j', 'y', 'h', 'k'};

  algorithms::sorting::CountingSort(integers, *(std::max_element(integers, integers + 11)));
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithms::sorting::CountingSort(chars, *(std::max_element(chars, chars + 8)));
  std::cout << "Sorted character array: ";
  algorithms::sorting::PrintArray(chars);  // a b d g h j k y

  return 0;
}