#include "sorting_util.h"

namespace algorithms {
namespace sorting {

template <class T, size_t N>
void Merge(T (&array)[N], int low, int mid, int high) {
  int l_len = mid - low + 1, r_len = high - mid;
  T *l_arr = new T[l_len], *r_arr = new T[r_len];

  for (int i = 0; i < l_len; i++) l_arr[i] = array[low + i];
  for (int i = 0; i < r_len; i++) r_arr[i] = array[mid + 1 + i];

  int i = 0, j = 0, k = low;
  while (i < l_len && j < r_len) array[k++] = l_arr[i] <= r_arr[j] ? l_arr[i++] : r_arr[j++];
  while (i < l_len) array[k++] = l_arr[i++];
  while (j < r_len) array[k++] = r_arr[j++];

  delete[] l_arr;
  delete[] r_arr;
}

template <class T, size_t N>
void MergeSort(T (&array)[N], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    MergeSort(array, low, mid);
    MergeSort(array, mid + 1, high);
    Merge(array, low, mid, high);
  }
}

}  // namespace sorting
}  // namespace algorithms

int main() {
  int integers[11] = {6, 8, 10, 26, 9, 2, 40, 22, 5, 32, 3};
  std::string strings[7] = {"c", "java", "cpp", "python", "go", "swift", "objective-c"};
  float floats[8] = {5.2f, 4.4f, 6.8f, 9.5f, 0.7f, 1.2f, 3.2f, 5.9f};

  algorithms::sorting::MergeSort(integers, 0, sizeof(integers) / sizeof(*integers) - 1);
  std::cout << "Sorted integer array: ";
  algorithms::sorting::PrintArray(integers);  // 2 3 5 6 8 9 10 22 26 32 40

  algorithms::sorting::MergeSort(strings, 0, sizeof(strings) / sizeof(*strings) - 1);
  std::cout << "Sorted string array: ";
  algorithms::sorting::PrintArray(strings);  // c cpp go java objective-c python swift

  algorithms::sorting::MergeSort(floats, 0, sizeof(floats) / sizeof(*floats) - 1);
  std::cout << "Sorted float array: ";
  algorithms::sorting::PrintArray(floats);  // 0.7 1.2 3.2 4.4 5.2 5.9 6.8 9.5

  return 0;
}