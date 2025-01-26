#include <bits/stdc++.h>

using namespace std;

struct Board {
  Board() : found(false) {}

  void Input() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c;
        cin >> c;
        m[i][j] = c - '0';
      }
    }
  }

  void Print() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) cout << (int)m[i][j];
      cout << "\n";
    }
  }

  bool Check(int y, int x, int v) {
    int sy = y - y % 3;
    int sx = x - x % 3;
    for (int i = 0; i < 9; i++) {
      if (m[i][x] == v) return false;
      if (m[y][i] == v) return false;
      if (m[sy + i / 3][sx + i % 3] == v) return false;
    }
    return true;
  }

  void Solve(int yx = 0) {
    if (found) return;
    if (found = yx == 81) return;
    int y = yx / 9;
    int x = yx % 9;

    if (m[y][x] == 0) {
      for (int i = 1; i <= 9; i++) {
        if (Check(y, x, i)) {
          m[y][x] = i;
          Solve(yx + 1);
          if (!found) m[y][x] = 0;
        }
      }
    } else {
      Solve(yx + 1);
    }
  }

  array<array<uint8_t, 9>, 9> m;
  bool found;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Board board;
  board.Input();
  board.Solve();
  board.Print();

  return 0;
}
