#include <iostream>

namespace algorithms {
namespace dynamic_programming {

unsigned int CatalanNumber(const unsigned int n) {
  unsigned int *catalan = new unsigned int[n + 1];
  catalan[0] = catalan[1] = 1;
  for (unsigned int i = 2; i <= n; i++) {
    catalan[i] = 0;
    for (unsigned int j = 0; j < i; j++)
      catalan[i] += catalan[j] * catalan[i - j - 1];
  }
  unsigned int ret = catalan[n];
  delete[] catalan;
  return ret;
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main() {
  const unsigned int n = 9;
  std::cout << "The " << n << "th catalan number is: ";
  std::cout << algorithms::dynamic_programming::CatalanNumber(n);
  std::cout << std::endl;
  return 0;
}
