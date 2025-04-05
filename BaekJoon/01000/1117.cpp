// Title : 색칠 1
// Link  : https://www.acmicpc.net/problem/1117
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint64_t w, h, f, c, x1, y1, x2, y2;
  cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

  uint64_t painted;
  uint64_t x = min<int>(f, w - f);
  if (x2 <= x) {
    painted = (x2 - x1) * 2;
  } else if (x <= x1) {
    painted = x2 - x1;
  } else {
    painted = (x - x1) * 2 + (x2 - x);
  }
  painted *= (y2 - y1) * (c + 1);

  cout << (w * h - painted) << endl;

  return 0;
}
