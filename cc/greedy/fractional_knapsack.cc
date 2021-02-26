#include <algorithm>
#include <iostream>
#include <tuple>

namespace algorithms {
namespace dynamic_programming {

bool FractionalKnapsackItemComparator(
    const std::tuple<unsigned int, unsigned int> a,
    const std::tuple<unsigned int, unsigned int> b) {
  return (std::get<1>(a) / std::get<0>(a)) > (std::get<1>(b) / std::get<0>(b));
}

template <size_t N>
unsigned int FractionalKnapsack(
    std::tuple<unsigned int, unsigned int> (&items)[N], unsigned int weight) {
  std::sort(items, items + N, FractionalKnapsackItemComparator);
  unsigned int maxValue = 0;
  for (std::tuple<unsigned int, unsigned int> item : items) {
    if (weight <= 0) break;
    if (weight < std::get<0>(item)) {
      maxValue += weight * std::get<1>(item) / std::get<0>(item);
      weight = 0;
    } else {
      maxValue += std::get<1>(item);
      weight -= std::get<0>(item);
    }
  }
  return maxValue;
}

}  // namespace dynamic_programming
}  // namespace algorithms

int main() {
  std::tuple<unsigned int, unsigned int> items[] = {std::make_tuple(10, 60),
                                                    std::make_tuple(30, 120),
                                                    std::make_tuple(20, 100)};
  unsigned int weight = 50;
  std::cout << algorithms::dynamic_programming::FractionalKnapsack(items,
                                                                   weight)
            << std::endl;
  return 0;
}
