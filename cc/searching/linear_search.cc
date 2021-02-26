#include <iostream>

namespace algorithms {
namespace searching {

template <class T, size_t N>
int LinearSearch(T (&array)[N], T key) {
  for (unsigned int i = 0; i < N; i++)
    if (array[i] == key) return i;
  return -1;
}

}  // namespace searching
}  // namespace algorithms

int main() {
  int integers[11] = {2, 3, 5, 6, 8, 9, 10, 22, 26, 32, 40};
  std::string strings[7] = {"c",           "cpp",    "go",   "java",
                            "objective-c", "python", "swift"};
  float floats[8] = {0.7f, 1.2f, 3.2f, 4.4f, 5.2f, 5.9f, 6.8f, 9.5f};

  std::cout << "Integer array: index of 8 is "
            << algorithms::searching::LinearSearch(integers, 8)
            << ", index of 1 is "
            << algorithms::searching::LinearSearch(integers, 1)
            << std::endl;  // 4, -1

  std::cout << "String array: index of \"cpp\" is "
            << algorithms::searching::LinearSearch(strings, (std::string) "cpp")
            << ", index of \"rust\" is "
            << algorithms::searching::LinearSearch(strings,
                                                   (std::string) "rust")
            << std::endl;  // 1, -1

  std::cout << "Float array: index of 9.5 is "
            << algorithms::searching::LinearSearch(floats, 9.5f)
            << ", index of 4.5 is "
            << algorithms::searching::LinearSearch(floats, 4.5f)
            << std::endl;  // 7, -1

  return 0;
}