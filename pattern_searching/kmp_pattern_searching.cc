#include <iostream>

namespace algorithms {
namespace pattern_searching {

template <size_t N, size_t M>
void KMPPatternSearching(const char (&text)[N], const char (&pattern)[M]) {
  unsigned int lsp[M - 1];
  unsigned int i = 1, j = 0;
  lsp[0] = 0;
  while (i < M - 1) {
    if (pattern[i] == pattern[j])
      lsp[i++] = ++j;
    else if (j > 0)
      j = lsp[j - 1];
    else
      lsp[i++] = j;
  }
  j = 0;
  for (i = 0; i < N - 1; i++) {
    if (j >= M - 2) break;
    if (text[i] == pattern[j])
      j++;
    else if (j > 0)
      j = lsp[j - 1];
  }
  if (j == M - 2) std::cout << "Pattern found at index " << i - j << std::endl;
}

}  // namespace pattern_searching
}  // namespace algorithms

int main() {
  char text[] = "ABABDABACDABABCABAB";
  char pattern[] = "ABABCABAB";
  algorithms::pattern_searching::KMPPatternSearching(text, pattern);
  return 0;
}
