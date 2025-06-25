// Title : Pyramid
// Link  : https://www.acmicpc.net/problem/15204 
// Time  : 1052 ms
// Memory: 2280 KB

#include <bits/stdc++.h>

using namespace std;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  int limit = 1 << n;
  vector<int64_t> brr(limit);
  for (int i = 1; i < limit; i++) {
    int lsb = i & (-i);
    int rem = i - lsb;
    if (rem == 0) {
      brr[i] = arr[countr_zero((uint32_t)lsb)];
    } else {
      brr[i] = brr[rem] * (brr[lsb] / GCD(brr[rem], brr[lsb]));
    }
  }

  auto Count = [&](int64_t x) {
    int64_t sum = 0;
    int limit = 1 << n;
    for (int i = 1; i < limit; i++) {
      int s = ((popcount(((uint32_t)i)) & 1) << 1) - 1;
      sum += (x / brr[i]) * s;
    }
    return sum;
  };

  while (m--) {
    int64_t x;
    cin >> x;

    int64_t lo = 1, hi = 1e18;
    while (lo + 1 < hi) {
      int64_t mid = (lo + hi) >> 1;
      if (Count(mid) < x) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << hi << "\n";
  }

  return 0;
}
