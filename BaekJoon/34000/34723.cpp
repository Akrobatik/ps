// Title : 피막치
// Link  : https://www.acmicpc.net/problem/34723 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c, x;
  cin >> a >> b >> c >> x;

  int64_t minn = INT_MAX;
  for (int64_t i = 1; i <= a; i++) {
    for (int64_t j = 1; j <= b; j++) {
      for (int64_t k = 1; k <= c; k++) {
        int64_t v = (i + j) * (j + k);
        int64_t dt = abs(v - x);
        if (minn > dt) minn = dt;
      }
    }
  }
  cout << minn;

  return 0;
}