#include <algorithm>
#include <iostream>
#include <tuple>

namespace algorithms {
namespace dynamic_programming {

bool ZeroOneKnapsackItemComparator(
    const std::tuple<unsigned int, unsigned int> a,
    const std::tuple<unsigned int, unsigned int> b) {
  return std::get<0>(a) < std::get<0>(b);
}

template <size_t N>
unsigned int ZeroOneKnapsack(std::tuple<unsigned int, unsigned int> (&items)[N],
                             const unsigned int weight) {
  std::sort(items, items + N, ZeroOneKnapsackItemComparator);
  unsigned int **matrix = new unsigned int *[N];
  for (unsigned int i = 0; i < N; i++) matrix[i] = new unsigned int[weight + 1];
  for (unsigned int i = 0; i < N; i++) {
    matrix[i][0] = 0;
    for (unsigned int j = 1; j <= weight; j++)
      matrix[i][j] =
          (i == 0) ? std::get<1>(items[i])
          : (j < std::get<0>(items[i]))
              ? matrix[i - 1][j]
              : std::max(std::get<1>(items[i]) +
                             matrix[i - 1][j - std::get<0>(items[i])],
                         matrix[i - 1][j]);
  }
  unsigned int ret = matrix[N - 1][weight];
  for (unsigned int i = 0; i < N; i++) delete[] matrix[i];
  delete[] matrix;
  return ret;
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main() {
  std::tuple<unsigned int, unsigned int> items[] = {
      std::make_tuple(1, 1), std::make_tuple(4, 5), std::make_tuple(3, 4),
      std::make_tuple(5, 7)};
  unsigned int weight = 7;
  std::cout << algorithms::dynamic_programming::ZeroOneKnapsack(items, weight)
            << std::endl;
  return 0;
}
