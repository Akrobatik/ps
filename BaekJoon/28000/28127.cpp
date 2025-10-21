// Title : 숫자탑과 쿼리
// Link  : https://www.acmicpc.net/problem/28127 
// Time  : 220 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, d, x;
    cin >> a >> d >> x;

    auto Calc = [&](int64_t v) {
      int64_t l = a, r = a + (v - 1) * d;
      return (l + r) * v / 2;
    };

    int64_t lo = 0, hi = x + 1;
    while (lo + 1 < hi) {
      int64_t mid = (lo + hi) >> 1;
      if (Calc(mid) < x) {
        lo = mid;
      } else {
        hi = mid;
      }
    }

    int64_t s = Calc(lo);
    int64_t r = x - s;
    cout << lo + 1 << " " << r << "\n";
  }

  return 0;
}