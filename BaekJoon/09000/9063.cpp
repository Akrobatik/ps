// Title : 대지
// Link  : https://www.acmicpc.net/problem/9063 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int minx = 10000, maxx = -10000;
  int miny = 10000, maxy = -10000;

  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    minx = min<int>(minx, x), maxx = max<int>(maxx, x);
    miny = min<int>(miny, y), maxy = max<int>(maxy, y);
  }

  cout << (int64_t)(maxx - minx) * (maxy - miny);

  return 0;
}
