#include <iostream>

namespace algorithms {
namespace mathematics {

int Factorial(int n) {
  if (n == 0) return 1;
  return n * Factorial(n - 1);
}

}  // namespace mathematics
}  // namespace algorithms

int main() {
  std::cout << "Factorial: ";
  std::cout << algorithms::mathematics::Factorial(6) << std::endl;  // 720

  return 0;
}