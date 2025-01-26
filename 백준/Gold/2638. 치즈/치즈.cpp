#include <bits/stdc++.h>

using namespace std;

struct Matrix {
  Matrix() : cols(0) {}
  Matrix(int _rows, int _cols) : cols(_cols), m(_rows * _cols, 0) {}

  uint8_t* operator[](int row) { return m.data() + row * cols; }

  int cols;
  vector<uint8_t> m;
};

struct Room {
  Room(int _rows, int _cols)
      : rows(_rows), cols(_cols), m(_rows, _cols), visited(_rows, _cols) {}

  uint8_t* operator[](int row) { return m[row]; }

  void Traverse(int y, int x) {
    if (m[y][x] != 0) return;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
      static constexpr int8_t dy[] = {0, 0, 1, -1};
      static constexpr int8_t dx[] = {1, -1, 0, 0};

      int16_t yy = y + dy[i];
      int16_t xx = x + dx[i];
      if (0 <= yy && yy < rows && 0 <= xx && xx < cols && !visited[yy][xx]) {
        if (m[yy][xx] == 0) {
          Traverse(yy, xx);
        } else if (m[yy][xx]) {
          m[yy][xx]++;
        }
      }
    }
  }

  bool Dispose() {
    memset(visited.m.data(), 0, visited.m.size());
    bool finish = true;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (m[i][j] > 2) {
          m[i][j] = 0;
        } else if (m[i][j]) {
          m[i][j] = 1;
          finish = false;
        }
      }
    }
    return finish;
  }

  bool Process() {
    Traverse(0, 0);
    Traverse(rows - 1, 0);
    Traverse(0, cols - 1);
    Traverse(rows - 1, cols - 1);
    return Dispose();
  }

  int rows, cols;
  Matrix m, visited;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int rows, cols;
  cin >> rows >> cols;
  Room room(rows, cols);
  bool empty = true;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> room[i][j];
      room[i][j] &= 1;
      if (room[i][j]) empty = false;
    }
  }

  int ans = 0;
  if (!empty) {
    do ans++;
    while (!room.Process());
  }

  cout << ans << endl;

  return 0;
}
