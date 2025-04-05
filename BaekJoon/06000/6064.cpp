// Title : 카잉 달력
// Link  : https://www.acmicpc.net/problem/6064
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
  int c = a % b;
  if (c == 0) return b;
  return GCD(b, c);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    if (y == n) y = 0;
    int maxx = (m * n) / GCD(m, n);
    bool found = false;
    for (x; x <= maxx; x += m) {
      if (x % n == y) {
        found = true;
        break;
      }
    }
    cout << (found ? x : -1) << "\n";
  }

  return 0;
}
