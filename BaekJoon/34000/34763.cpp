// Title : 땅따먹기
// Link  : https://www.acmicpc.net/problem/34763 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k, ++n;
    int64_t half = n >> 1;

    auto Calc = [&](int64_t x) {
      return x * (n - x);
    };

    int64_t lb = Calc(1), ub = Calc(half);
    if (lb <= k && k <= ub) {
      int64_t lo = 0, hi = half;
      while (lo + 1 < hi) {
        int64_t mid = (lo + hi) >> 1;
        if (Calc(mid) < k) {
          lo = mid;
        } else {
          hi = mid;
        }
      }
      cout << (Calc(hi) == k ? "YES\n" : "NO\n");
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}