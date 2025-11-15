// Title : 버섯이 나 있어!!!
// Link  : https://www.acmicpc.net/problem/33625 
// Time  : 472 ms
// Memory: 267700 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

int fwd[kMax + 1][32];
basic_string<int> keys[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 32; j++) {
      fwd[i][j] = fwd[i - 1][j];
    }

    uint32_t x;
    cin >> x;
    while (x) {
      uint32_t lsb = x & -x;
      x ^= lsb;
      int k = countl_zero(lsb);
      keys[i].push_back(k);
      fwd[i][k] += 1;
    }
  }

  auto Check = [&](int len) {
    for (int i = len; i <= n; i++) {
      bool ok = true;
      for (auto k : keys[i]) {
        if (fwd[i][k] - fwd[i - len][k] == len) {
          ok = false;
          break;
        }
      }
      if (ok) return true;
    }
    return false;
  };

  int lo = 0, hi = n + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << (hi <= n ? hi + n - 2 : -1);

  return 0;
}