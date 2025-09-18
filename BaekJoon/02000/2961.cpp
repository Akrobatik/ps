// Title : 도영이가 만든 맛있는 음식
// Link  : https://www.acmicpc.net/problem/2961 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kLimit = 1e11;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;

  auto Check = [&](uint32_t x) {
    __int128_t as = 1;
    while (x) {
      uint32_t lsb = x & (-x);
      int crz = countr_zero(lsb);

      auto [a, b] = arr[crz];
      as *= a;
      if (as >= kLimit) return false;

      x ^= lsb;
    }
    return as <= kLimit;
  };

  int limit = 1 << n;
  int64_t minn = INT64_MAX;
  for (int i = 1; i < limit; i++) {
    uint32_t x = i;
    int64_t as = 1, bs = 0;
    while (x) {
      uint32_t lsb = x & (-x);
      int crz = countr_zero(lsb);

      auto [a, b] = arr[crz];
      as *= a, bs += b;

      x ^= lsb;
    }
    int64_t cur = abs(as - bs);
    minn = min<int64_t>(minn, cur);
  }
  cout << minn;

  return 0;
}