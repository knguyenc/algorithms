#include "sorting_util.h"

namespace algorithms {
namespace sorting {

template <class T, size_t N>
int Partition(T (&array)[N], int low, int high) {
  T pivot = array[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
    if (array[j] < pivot)
      std::swap(array[++i], array[j]);
  std::swap(array[i + 1], array[high]);
  return i + 1;
}

template <class T, size_t N>
int HoarePartition(T (&array)[N], int low, int high) {
  T pivot = array[low];
  int i = low - 1, j = high + 1;
  while (true) {
    do {
      i++;
    } while (array[i] < pivot);
    do {
      j--;
    } while (array[j] > pivot);
    if (i < j) std::swap(array[i], array[j]);
    else return j;
  }
}

template <class T, size_t N>
void QuickSort(T (&array)[N], int low, int high) {
  if (low < high) {
    int separator = Partition(array, low, high);
    // remember to pass `separator` instead of `separator - 1` when using hoare partition
    QuickSort(array, low, separator - 1);
    QuickSort(array, separator + 1, high);
  }
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[7] = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithms::sorting::QuickSort(integers, 0, sizeof(integers) / sizeof(*integers) - 1);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithms::sorting::QuickSort(strings, 0, sizeof(strings) / sizeof(*strings) - 1);
  std::cout << "Sorted string array: ";
  algorithms::sorting::PrintArray(strings);  // c cpp go java objective-c python swift

  algorithms::sorting::QuickSort(floats, 0, sizeof(floats) / sizeof(*floats) - 1);
  std::cout << "Sorted float array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}