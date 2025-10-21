// Title : Thread Knots
// Link  : https://www.acmicpc.net/problem/17976 
// Time  : 24 ms
// Memory: 3588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int64_t, int64_t>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;
  sort(arr.begin(), arr.end());

  auto Check = [&](int64_t x) {
    int64_t prv = arr[0].first;
    for (int i = 1; i < n; i++) {
      auto [a, b] = arr[i];
      int64_t cur = prv + x;
      if (cur > a) {
        if (cur > a + b) return false;
        prv = cur;
      } else {
        prv = a;
      }
    }
    return true;
  };

  int64_t lo = 0, hi = INT_MAX;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}