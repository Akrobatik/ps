// Title : 포도주 상인
// Link  : https://www.acmicpc.net/problem/34850 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, y, p, a, b;
  cin >> x >> y >> p >> a >> b;

  int64_t hi = p + b * (y - 1);
  int64_t lo = hi - a * (x - 1);

  cout << (hi + lo) * x / 2;

  return 0;
}