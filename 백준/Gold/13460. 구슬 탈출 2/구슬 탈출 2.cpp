#include <bits/stdc++.h>

using namespace std;

struct Board {
  Board(int r, int c) : rows(r), cols(c), m(r * c) {}

  char* operator[](int row) { return m.data() + row * cols; }
  const char* operator[](int row) const { return m.data() + row * cols; }

  int rows, cols;
  int ry, rx, by, bx;
  vector<char> m;
};

int Solve(const Board& board, int depth) {
  if (depth == 10) return INT_MAX;

  int minn = INT_MAX;
  for (int i = 0; i < 4; i++) {
    Board b(board);
    int dy = i < 2 ? 0 : (i & 1 ? -1 : 1);
    int dx = i < 2 ? (i & 1 ? -1 : 1) : 0;
    int ry = b.ry + dy, rx = b.rx + dx;
    int by = b.by + dy, bx = b.bx + dx;

    bool ro = false;
    while (0 <= ry && ry < b.rows && 0 <= rx && rx < b.cols) {
      if (b[ry][rx] != '.') {
        if (b[ry][rx] == 'O') {
          ro = true;
          b[b.ry][b.rx] = '.';
        }
        break;
      }
      ry += dy, rx += dx;
    }
    swap(b[ry - dy][rx - dx], b[b.ry][b.rx]);
    b.ry = ry - dy, b.rx = rx - dx;

    bool bo = false;
    while (0 <= by && by < b.rows && 0 <= bx && bx < b.cols) {
      if (b[by][bx] != '.') {
        bo = b[by][bx] == 'O';
        break;
      }
      by += dy, bx += dx;
    }
    swap(b[by - dy][bx - dx], b[b.by][b.bx]);
    b.by = by - dy, b.bx = bx - dx;

    if (bo) continue;
    if (ro) return depth + 1;

    while (0 <= ry && ry < b.rows && 0 <= rx && rx < b.cols) {
      if (b[ry][rx] != '.') break;
      ry += dy, rx += dx;
    }
    swap(b[ry - dy][rx - dx], b[b.ry][b.rx]);
    b.ry = ry - dy, b.rx = rx - dx;

    int v = Solve(b, depth + 1);
    minn = min<int>(minn, v);
  }
  return minn == INT_MAX && depth == 0 ? -1 : minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  Board board(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') board.ry = i, board.rx = j;
      if (board[i][j] == 'B') board.by = i, board.bx = j;
    }
  }

  cout << Solve(board, 0);

  return 0;
}
