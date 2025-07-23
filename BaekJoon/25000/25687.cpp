// Title : 2차원
// Link  : https://www.acmicpc.net/problem/25687 
// Time  : 48 ms
// Memory: 33188 KB

#include <bits/stdc++.h>

using namespace std;

constexpr array<uint32_t, 10000> kTable = []() {
  array<uint32_t, 10000> table{};
  for (int i = 0; i < 10000; i++) {
    uint32_t x = 0, v = i;
    for (int j = 0; j < 4; j++, v /= 10) {
      x = (x << 8) + v % 10 + 48;
    }
    table[i] = x;
  }
  return table;
}();

inline uint64_t Get(int x) {
  x *= 10;
  int fw = x / 10000, bw = x % 10000;
  return ((uint64_t)(kTable[bw] ^ 0x10000000) << 32) | kTable[fw];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t buf[4000000];
  auto it = buf;

  int n;
  cin >> n;
  int m = n * n;
  int b1 = n, b2 = n, s = n - 1;
  while (b1 < m) {
    for (int x = b1; x <= m; x += n) *it++ = Get(x);
    for (int x = b2; x < b1; x += n) *it++ = Get(x);
    it[-1] ^= (0x2AULL << 56);
    b1 += s, --b2;
  }
  fwrite(buf, 1, (it - buf) * 8, stdout);

  return 0;
}
