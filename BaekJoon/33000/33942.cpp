// Title : MEX의 MEX
// Link  : https://www.acmicpc.net/problem/33942 
// Time  : 64 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

__int128_t Calc(int64_t n) {
  if (n <= 1) return 0;
  __int128_t x = (__int128_t)n * (n - 1) / 2;
  __int128_t q = n / 3, r = (n - 2) / 3;
  return x + (r << 1) + q;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t lo = 1, hi = n + 100;
    while (lo + 1 < hi) {
      int64_t mid = (lo + hi) >> 1;
      if (Calc(mid) <= (__int128_t)n) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    cout << lo << "\n";
  }

  return 0;
}
