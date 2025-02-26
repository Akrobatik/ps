#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char cells[10][10], ans[10][10];
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> cells[i][j];
      ans[i][j] = cells[i][j];
    }
  }

  int miny = 9, maxy = 0, minx = 9, maxx = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (cells[i][j] == '.') continue;
      int cnt = 0;
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (0 <= y && y < r && 0 <= x && x < c && cells[y][x] == 'X') {
          ++cnt;
        }
      }

      if (cnt <= 1) {
        ans[i][j] = '.';
      } else {
        miny = min<int>(miny, i), maxy = max<int>(maxy, i);
        minx = min<int>(minx, j), maxx = max<int>(maxx, j);
      }
    }
  }

  for (int i = miny; i <= maxy; i++) {
    for (int j = minx; j <= maxx; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }

  return 0;
}
