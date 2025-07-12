// Title : 배고파(Hard)
// Link  : https://www.acmicpc.net/problem/28245 
// Time  : 4 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<uint64_t> arr;
  for (int i = 0; i <= 62; i++) {
    uint64_t x = 1ULL << i;
    for (int j = i; j <= 62; j++) {
      uint64_t y = 1ULL << j;
      arr.push_back(x + y);
    }
  }
  sort(arr.begin(), arr.end());

  int t;
  cin >> t;
  while (t--) {
    uint64_t m;
    cin >> m;
    if (m <= 2) {
      cout << "0 0\n";
      continue;
    }

    auto it = lower_bound(arr.begin(), arr.end(), m);
    uint64_t rv = *it, lv = *--it;
    uint64_t v = (m - lv <= rv - m ? lv : rv);
    uint64_t lsb = v & (-v);
    uint64_t msb = v ^ lsb;
    if (msb == 0) {
      int x = countr_zero(lsb) - 1;
      cout << x << " " << x << "\n";
    } else {
      cout << countr_zero(lsb) << " " << countr_zero(msb) << "\n";
    }
  }

  return 0;
}