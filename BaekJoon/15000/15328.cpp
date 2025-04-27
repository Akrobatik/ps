// Title : 산타의 선물
// Link  : https://www.acmicpc.net/problem/15328 
// Time  : 544 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

constexpr long double kEpsilon = 1e-18;

__float128 Sqrt(__float128 n) {
  __float128 lo = 0, hi = n;
  while (lo + kEpsilon < hi) {
    __float128 mid = (lo + hi) / 2;
    if (mid * mid <= n) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int rem;
    cin >> rem;
    __float128 r = rem;

    __float128 sum = 0;
    int sx = 0, sy = 0, sz = 0;
    for (int i = 0; i < 4; i++) {
      int dx, dy, dz;
      cin >> dx >> dy >> dz;
      int xx = sx - dx, yy = sy - dy, zz = sz - dz;
      sum += Sqrt(xx * xx + yy * yy + zz * zz);
      sx = dx, sy = dy, sz = dz;
    }

    if (sum <= r) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
