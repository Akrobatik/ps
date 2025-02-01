#include <bits/stdc++.h>

using namespace std;

int rows, cols;
int rm, cm;
int board[100][100];

struct Shark {
  bool Move() {
    ry += dy, rx += dx;
    if (ry >= rm) ry -= rm;
    if (rx >= cm) rx -= cm;
    y = ry < rows ? ry : rm - ry;
    x = rx < cols ? rx : cm - rx;

    if (board[y][x] < size) {
      board[y][x] = size;
      return true;
    }
    return false;
  }

  int size, y, x, ry, rx, dy, dx;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> rows >> cols >> m;
  rm = (rows - 1) << 1;
  cm = (cols - 1) << 1;
  vector<Shark> sharks(m);
  for (int i = 0; i < m; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    --r, --c;
    s %= d <= 2 ? rm : cm;
    sharks[i].y = sharks[i].ry = r;
    sharks[i].x = sharks[i].rx = c;
    sharks[i].size = z;
    sharks[i].dy = d <= 2 ? (d & 1 ? rm - s : s) : 0;
    sharks[i].dx = d <= 2 ? 0 : (d & 1 ? s : cm - s);
  }

  sort(sharks.begin(), sharks.end(), [](const Shark& lhs, const Shark& rhs) {
    return lhs.size < rhs.size;
  });

  int sum = 0;
  for (int i = 0; i < cols; i++) {
    if (sharks.empty()) break;

    int id;
    int y = INT_MAX;
    for (int j = 0; j < sharks.size(); j++) {
      auto& shark = sharks[j];
      if (shark.x == i && y > shark.y) y = shark.y, id = j;
    }
    if (y != INT_MAX) {
      sum += sharks[id].size;
      sharks.erase(sharks.begin() + id);
    }

    fill_n((int*)board, 100 * 100, -1);
    int n = sharks.size();
    for (int j = n - 1; j >= 0; j--) {
      if (!sharks[j].Move()) {
        sharks.erase(sharks.begin() + j);
      }
    }
  }

  cout << sum;

  return 0;
}
