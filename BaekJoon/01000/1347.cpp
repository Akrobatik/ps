// Title : 미로 만들기
// Link  : https://www.acmicpc.net/problem/1347
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char cells[99][99];
  fill_n((char*)cells, 99 * 99, '#');
  cells[49][49] = '.';
  int y = 49, x = 49;
  int miny = 49, maxy = 49;
  int minx = 49, maxx = 49;
  int dy = 1, dx = 0;

  int n;
  cin >> n;
  while (n--) {
    char op;
    cin >> op;
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

  for (int i = miny; i <= maxy; i++) {
    for (int j = minx; j <= maxx; j++) cout << cells[i][j];
    cout << "\n";
  }

  return 0;
}
