#include <iostream>
#include <tuple>

namespace algorithms {
namespace mathematics {

int BinaryFibonacci(int n) {
  if (n <= 1) return n;
  return BinaryFibonacci(n - 1) + BinaryFibonacci(n - 2);
}

std::tuple<int, int> LinearFibonacci(int n) {
  if (n <= 1) return std::make_tuple(n, 0);
  std::tuple<int, int> ret = LinearFibonacci(n - 1);
  return std::make_tuple(std::get<0>(ret) + std::get<1>(ret), std::get<0>(ret));
}

}  // namespace mathematics
}  // namespace algorithms

int main() {
  std::cout << "Binary fibonacci: ";
  std::cout << algorithms::mathematics::BinaryFibonacci(6) << std::endl;  // 8

  std::cout << "Linear fibonacci: ";
  std::cout << std::get<0>(algorithms::mathematics::LinearFibonacci(6))
            << std::endl;  // 8

  return 0;
}
