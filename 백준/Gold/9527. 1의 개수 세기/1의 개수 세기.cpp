#include <bits/stdc++.h>

using namespace std;

constexpr uint64_t A = 1e16;
constexpr uint64_t B = 1ull << 54;

static_assert(A <= B);

uint64_t Calc(uint64_t n) {
  uint64_t sum = 0;
  for (uint64_t i = 54; i > 0; i--) {
    if (n & (1ull << i)) {
      sum += (i << (i - 1)) + n - (1ull << i) + 1;
      n ^= 1ull << i;
    }
  }
  return sum + n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t a, b;
  cin >> a >> b;
  cout << Calc(b) - Calc(a - 1) << endl;

  return 0;
}
