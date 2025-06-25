// Title : Pyramid
// Link  : https://www.acmicpc.net/problem/15204 
// Time  : 792 ms
// Memory: 2540 KB

#pragma GCC optimize("O3")
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
  vector<pair<int64_t, int>> brr(limit);
  for (int i = 1; i < limit; i++) {
    int lsb = i & (-i);
    int rem = i - lsb;
    int sign = ((popcount((uint32_t)i) & 1) << 1) - 1;
    if (rem == 0) {
      brr[i] = {arr[countr_zero((uint32_t)lsb)], sign};
    } else {
      brr[i] = {brr[rem].first * (brr[lsb].first / GCD(brr[rem].first, brr[lsb].first)), sign};
    }
  }

  sort(brr.begin(), brr.end());

  auto Count = [&](int64_t x) {
    int64_t sum = 0;
    int limit = 1 << n;
    for (int i = 1; i < limit; i++) {
      if (brr[i].first > x) break;
      sum += (x / brr[i].first) * brr[i].second;
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
