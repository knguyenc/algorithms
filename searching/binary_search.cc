#include <iostream>

namespace algorithms {
namespace searching {

template <class T, size_t N>
int BinarySearch(T (&array)[N], T key, int low, int high) {
  if (low > high) return -1;
  int middle = (low + high) / 2;
  if (array[middle] == key)
    return middle;
  else if (key < array[middle])
    return BinarySearch(array, key, low, middle - 1);
  else
    return BinarySearch(array, key, middle + 1, high);
}

}  // namespace searching
}  // namespace algorithms

int main() {
  int integers[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string strings[7] = {"c", "cpp", "go", "java", "objective-c", "python", "swift"};
  float floats[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  std::cout << "Integer array: index of 8 is "
            << algorithms::searching::BinarySearch(integers, 8, 0, sizeof(integers) / sizeof(*integers) - 1)
            << ", index of 1 is "
            << algorithms::searching::BinarySearch(integers, 1, 0, sizeof(integers) / sizeof(*integers) - 1)
            << std::endl;  // 4, -1

  std::cout << "String array: index of \"cpp\" is "
            << algorithms::searching::BinarySearch(strings, (std::string) "cpp", 0,
                                                   sizeof(strings) / sizeof(*strings) - 1)
            << ", index of \"rust\" is "
            << algorithms::searching::BinarySearch(strings, (std::string) "rust", 0,
                                                   sizeof(strings) / sizeof(*strings) - 1)
            << std::endl;  // 1, -1

  std::cout << "Float array: index of 9.5 is "
            << algorithms::searching::BinarySearch(floats, 9.5f, 0, sizeof(floats) / sizeof(*floats) - 1)
            << ", index of 4.5 is "
            << algorithms::searching::BinarySearch(floats, 4.5f, 0, sizeof(floats) / sizeof(*floats) - 1)
            << std::endl;  // 7, -1

  return 0;
}