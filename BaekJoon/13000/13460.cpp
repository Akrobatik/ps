// Title : 구슬 탈출 2
// Link  : https://www.acmicpc.net/problem/13460
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int rows, cols;
char board[10][10];
int oy, ox;

int Solve(int ry, int rx, int by, int bx, int depth) {
  int minn = INT_MAX;
  if (depth == 10) return minn;

  for (int i = 0; i < 4; i++) {
    int dy = i < 2 ? 0 : (i & 1 ? -1 : 1);
    int dx = i < 2 ? (i & 1 ? -1 : 1) : 0;
    int rty = ry, rtx = rx;
    int bty = by, btx = bx;
    int nry = ry + dy, nrx = rx + dx;
    int nby = by + dy, nbx = bx + dx;

    auto clear = [&]() {
      board[rty][rtx] = board[bty][btx] = '.';
      board[oy][ox] = 'O';
      board[ry][rx] = 'R';
      board[by][bx] = 'B';
    };

    bool ro = false;
    bool rb = false;
    while (0 <= nry && nry < rows && 0 <= nrx && nrx < cols) {
      if (board[nry][nrx] != '.') {
        if (board[nry][nrx] == 'O') ro = true, board[rty][rtx] = '.';
        rb = board[nry][nrx] == 'B';
        break;
      }
      nry += dy, nrx += dx;
    }
    swap(board[rty][rtx], board[nry - dy][nrx - dx]);
    rty = nry - dy, rtx = nrx - dx;

    bool bo = false;
    while (0 <= nby && nby < rows && 0 <= nbx && nbx < cols) {
      if (board[nby][nbx] != '.') {
        bo = board[nby][nbx] == 'O';
        break;
      }
      nby += dy, nbx += dx;
    }
    swap(board[bty][btx], board[nby - dy][nbx - dx]);
    bty = nby - dy, btx = nbx - dx;

    if (bo) {
      clear();
      continue;
    }

    if (ro) {
      clear();
      return depth + 1;
    }

    if (rb) {
      while (0 <= nry && nry < rows && 0 <= nrx && nrx < cols) {
        if (board[nry][nrx] != '.') break;
        nry += dy, nrx += dx;
      }
      swap(board[rty][rtx], board[nry - dy][nrx - dx]);
      rty = nry - dy, rtx = nrx - dx;
    }

    if (ry == rty && rx == rtx && by == bty && bx == btx) {
      clear();
      continue;
    }

    int v = Solve(rty, rtx, bty, btx, depth + 1);
    minn = min<int>(minn, v);

    clear();
  }

  if (depth == 0 && minn == INT_MAX) return -1;
  return minn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> rows >> cols;
  int ry, rx, by, bx;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'R') ry = i, rx = j;
      if (board[i][j] == 'B') by = i, bx = j;
      if (board[i][j] == 'O') oy = i, ox = j;
    }
  }

  cout << Solve(ry, rx, by, bx, 0);

  return 0;
}
