#include "sorting_util.h"

namespace algorithms {
namespace sorting {

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
  std::string strings[7] = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithms::sorting::BubbleSort(integers);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithms::sorting::BubbleSort(strings);
  std::cout << "Sorted string array: ";
  algorithms::sorting::PrintArray(strings);  // c cpp go java objective-c python swift

  algorithms::sorting::BubbleSort(floats);
  std::cout << "Sorted float array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}