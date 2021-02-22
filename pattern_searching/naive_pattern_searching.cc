#include <iostream>

namespace algorithms {
namespace pattern_searching {

template <size_t N, size_t M>
void NaivePatternSearching(const char (&text)[N], const char (&pattern)[M]) {
  for (unsigned int i = 0; i < N - M; i++) {
    bool matched = true;
    for (unsigned int j = 0; j < M - 1; j++) {
      if (text[i + j] != pattern[j]) {
        matched = false;
        break;
      }
    }
    if (matched) std::cout << "Pattern found at index " << i << std::endl;
  }
}

}  // namespace pattern_searching
}  // namespace algorithms

int main() {
  char text[] = "AABAACAADAABAAABAA";
  char pattern[] = "AABA";
  algorithms::pattern_searching::NaivePatternSearching(text, pattern);
  return 0;
}
