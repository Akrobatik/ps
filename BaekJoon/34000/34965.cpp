// Title : 자기장 측정기
// Link  : https://www.acmicpc.net/problem/34965 
// Time  : 0 ms
// Memory: 2916 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t, int64_t>;

constexpr pair<int, int> kDelta[] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tx, ty;
  cin >> tx >> ty;

  int64_t cy = -ty, cx = -tx, cd = 0;

  char cmd;
  int val;
  vector<tup> lines;
  while (cin >> cmd >> val) {
    if (cmd == 'S') {
      auto [dy, dx] = kDelta[cd];
      int64_t ny = cy + val * dy, nx = cx + val * dx;
      lines.push_back({cy, cx, ny, nx});
      cy = ny, cx = nx;
    } else {
      cd = (cd + val) % 4;
    }
  }

  if (lines.empty()) lines.push_back({cy, cx, cy, cx});

  int64_t ay, ax;
  int64_t minn = INT64_MAX;
  for (auto [sy, sx, ey, ex] : lines) {
    int64_t y, x;
    if (sy == ey) {
      if (sx * ex < 0) {
        y = sy, x = 0;
      } else {
        if (abs(sx) < abs(ex)) {
          y = sy, x = sx;
        } else {
          y = sy, x = ex;
        }
      }
    } else {
      if (sy * ey < 0) {
        y = 0, x = sx;
      } else {
        if (abs(sy) < abs(ey)) {
          y = sy, x = sx;
        } else {
          y = ey, x = sx;
        }
      }
    }

    int64_t cur = y * y + x * x;
    if (minn > cur) minn = cur, ay = y, ax = x;
  }

  if (minn > 0) {
    cout << ax + tx << " " << ay + ty;
  } else {
    cout << "-1";
  }

  return 0;
}