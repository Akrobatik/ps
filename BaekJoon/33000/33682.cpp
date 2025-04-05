// Title : 하늘에서 떨어지는 $＼infty$개의 별
// Link  : https://www.acmicpc.net/problem/33682
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t s0, x, m, d, k;
  cin >> s0 >> x >> m >> d >> k;
  int64_t g = gcd(x, m);
  int64_t maxx = (((m - s0 - 1)) / g) * g + s0;

  int64_t lo = 1, hi = d + 1;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    __int128_t r = (__int128_t)maxx * mid;
    if (r <= (__int128_t)k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << (d - 1) / lo;

  return 0;
}
