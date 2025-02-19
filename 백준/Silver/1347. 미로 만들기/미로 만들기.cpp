#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 1 0
  // 0 -1
  // -1 0
  // 0 1
  // 1 0

  int n;
  cin >> n;
  vector<char> ops(n);
  for (int i = 0; i < n; i++) cin >> ops[i];

  int y = 0, x = 0;
  int miny = 0, maxy = 0;
  int minx = 0, maxx = 0;
  int dy = 1, dx = 0;
  for (auto op : ops) {
    if (op == 'R') {
      if (dy) {
        dx = -dy;
        dy = 0;
      } else {
        dy = dx;
        dx = 0;
      }
    } else if (op == 'L') {
      if (dy) {
        dx = dy;
        dy = 0;
      } else {
        dy = -dx;
        dx = 0;
      }
    } else {
      y += dy;
      x += dx;
      if (miny > y) {
        miny = y;
      } else if (maxy < y) {
        maxy = y;
      }
      if (minx > x) {
        minx = x;
      } else if (maxx < x) {
        maxx = x;
      }
    }
  }

  dy = 1, dx = 0;
  y = -miny, x = -minx;
  maxy -= miny, maxx -= minx;
  miny = minx = 0;
  vector<vector<char>> cells(maxy + 1, vector<char>(maxx + 1, '#'));
  cells[y][x] = '.';
  for (char op : ops) {
    if (op == 'R') {
      if (dy) {
        dx = -dy;
        dy = 0;
      } else {
        dy = dx;
        dx = 0;
      }
    } else if (op == 'L') {
      if (dy) {
        dx = dy;
        dy = 0;
      } else {
        dy = -dx;
        dx = 0;
      }
    } else {
      y += dy;
      x += dx;
      cells[y][x] = '.';
    }
  }

  for (auto& e : cells) {
    for (auto c : e) cout << c;
    cout << "\n";
  }

  return 0;
}
