#include <bits/stdc++.h>

using namespace std;

struct Cells : public vector<int> {
 public:
  Cells(int _rows, int _cols) : vector<int>(_rows * _cols, 0), cols(_cols) {}

  int* operator[](int row) { return data() + row * cols; }

  int cols;
};

struct Room {
  Room(int _rows, int _cols)
      : cells(_rows, _cols), cells_copy(_rows, _cols), rows(_rows), cols(_cols) {}

  void Diffuse() {
    static constexpr int dy[] = {0, 0, 1, -1};
    static constexpr int dx[] = {1, -1, 0, 0};

    memcpy(cells_copy.data(), cells.data(), rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (cells_copy[i][j] == -1) continue;
        int unit = cells_copy[i][j] / 5;
        for (int k = 0; k < 4; k++) {
          int y = i + dy[k];
          int x = j + dx[k];
          if (0 <= x && x < cols && 0 <= y && y < rows && cells_copy[y][x] != -1) {
            cells[y][x] += unit;
            cells[i][j] -= unit;
          }
        }
      }
    }
  }

  void MoveByWind() {
    memcpy(cells_copy.data(), cells.data(), rows * cols * sizeof(int));
    for (auto [y, x, dy, dx] : winds) {
      if (dy || dx)
        cells[y + dy][x + dx] = cells_copy[y][x];
      else
        cells[y][x] = 0;
    }
  }

  void MakeWinds(int cleaner) {
    winds.reserve(rows * 2 + cols * 4 - 10);
    for (int i = 1; i < cols; i++) {
      winds.push_back(make_tuple(0, i, 0, -1));
      winds.push_back(make_tuple(rows - 1, i, 0, -1));
    }
    winds.push_back(make_tuple(cleaner - 1, 1, 0, 0));
    winds.push_back(make_tuple(cleaner, 1, 0, 0));
    for (int i = 1; i < cols - 1; i++) {
      winds.push_back(make_tuple(cleaner - 1, i, 0, 1));
      winds.push_back(make_tuple(cleaner, i, 0, 1));
    }
    for (int i = 1; i < rows - 1; i++) {
      winds.push_back(make_tuple(i, cols - 1, i < cleaner ? -1 : 1, 0));
    }
    for (int i = 0; i < rows; i++) {
      if (i < cleaner - 2 || i > cleaner + 1)
        winds.push_back(make_tuple(i, 0, i < cleaner ? 1 : -1, 0));
    }
  }

  int CountDusts() {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (cells[i][j] != -1) sum += cells[i][j];
      }
    }
    return sum;
  }

  Cells cells, cells_copy;
  int rows, cols;
  vector<tuple<int, int, int, int>> winds;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, t;
  cin >> r >> c >> t;
  Room room(r, c);
  int cleaner;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> room.cells[i][j];
      if (room.cells[i][j] == -1) cleaner = i;
    }
  }
  room.MakeWinds(cleaner);

  for (int i = 0; i < t; i++) {
    room.Diffuse();
    room.MoveByWind();
  }

  cout << room.CountDusts() << endl;

  return 0;
}
