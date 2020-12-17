#include <iostream>
#include <tuple>
#include <climits>
#include <cstdint>

namespace algorithms {
namespace divide_conquer {

std::tuple<int, int, int> MaxCrossingSubarray(const int *array, int low, int mid, int high) {
  int l_sum = INT_MIN, r_sum = INT_MIN;
  int sum = 0, l_max = mid, r_max = mid + 1;

  for (int i = mid; i >= low; i--) {
    sum += array[i];
    if (sum > l_sum) {
      l_sum = sum;
      l_max = i;
    }
  }

  sum = 0;
  for (int i = mid + 1; i <= high; i++) {
    sum += array[i];
    if (sum > r_sum) {
      r_sum = sum;
      r_max = i;
    }
  }

  if (l_sum > r_sum && l_sum > (l_sum + r_sum))
    return std::make_tuple(l_max, mid, l_sum);
  else if (r_sum > l_sum && r_sum > (l_sum + r_sum))
    return std::make_tuple(mid + 1, r_max, r_sum);
  else
    return std::make_tuple(l_max, r_max, l_sum + r_sum);
}

std::tuple<int, int, int> MaximumSubarray(const int *array, int low, int high) {
  if (low == high) return std::make_tuple(low, high, array[low]);
  int mid = (low + high) / 2;

  std::tuple<int, int, int> l_tuple = MaximumSubarray(array, low, mid);
  std::tuple<int, int, int> r_tuple = MaximumSubarray(array, mid + 1, high);
  std::tuple<int, int, int> c_tuple = MaxCrossingSubarray(array, low, mid, high);

  if (std::get<2>(l_tuple) >= std::get<2>(r_tuple) && std::get<2>(l_tuple) >= std::get<2>(c_tuple)) return l_tuple;
  if (std::get<2>(r_tuple) >= std::get<2>(l_tuple) && std::get<2>(r_tuple) >= std::get<2>(c_tuple))
    return r_tuple;
  else
    return c_tuple;
}

}  // namespace divide_conquer
}  // namespace algorithms

int main() {
  int arr[16] = {12, -2, -23, 18, -1, -14, -21, 16, 19, -5, 10, -3, -20, 13, -4, -7};
  std::tuple<int, int, int> ret = algorithms::divide_conquer::MaximumSubarray(arr, 0, sizeof(arr) / sizeof(*arr));

  std::cout << "Start: " << std::get<0>(ret) << std::endl;  // 7
  std::cout << "End: " << std::get<1>(ret) << std::endl;    // 10
  std::cout << "Sum: " << std::get<2>(ret) << std::endl;    // 40

  return 0;
}
