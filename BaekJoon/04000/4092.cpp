// Title : 비트 개수 세기
// Link  : https://www.acmicpc.net/problem/4092 
// Time  : 0 ms
// Memory: 2052 KB

#include <bits/stdc++.h>

using namespace std;

int memo[64];
int64_t comb[64][64];

int64_t Count(int64_t n, int64_t x) {
  if (x == 0) return n != 0;

  array<int64_t, 64> arr{};
  int cnt = 0;
  for (int i = 62; i >= 0; i--) {
    if (n & (1ll << i)) {
      for (int j = 0; j <= i && j + cnt < 64; j++) {
        arr[j + cnt] += comb[i][j];
      }
      ++cnt;
    }
  }
  ++arr[cnt];

  int64_t res = 0;
  for (int i = 1; i < 64; i++) {
    if (memo[i] == x) res += arr[i];
  }
  return res - (x == 1 && n != 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[1] = 1;
  for (int i = 2; i < 64; i++) {
    bitset<32> bits(i);
    memo[i] = memo[bits.count()] + 1;
  }

  for (int i = 0; i < 64; i++) {
    int64_t x = 1;
    for (int j = 0; j <= i; j++) {
      comb[i][j] = x;
      x = x * (i - j) / (j + 1);
    }
  }

  int64_t lo, hi, x;
  while (cin >> lo >> hi >> x && (lo != 0 || hi != 0 || x != 0)) {
    auto r = Count(hi, x);
    auto l = Count(lo - 1, x);
    cout << r - l << "\n";
  }

  return 0;
}
