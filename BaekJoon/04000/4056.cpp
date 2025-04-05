// Title : 스－스－스도쿠
// Link  : https://www.acmicpc.net/problem/4056
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int board[9][9], int idx, int* yx, int* sub_masks, int* row_masks, int* col_masks) {
  if (idx == 5) {
    for (int i = 0; i < 9; i++) {
      constexpr int kMask = (1 << 9) - 1;
      if ((sub_masks[i] ^ kMask) || (row_masks[i] ^ kMask) || (col_masks[i] ^ kMask)) return false;
    }
    return true;
  }

  int y = yx[idx] >> 16;
  int x = yx[idx] & 0xF;
  for (int i = 0; i < 9; i++) {
    int m = 1 << i;
    int s = y - y % 3 + x / 3;
    if ((sub_masks[s] & m) || (row_masks[y] & m) || (col_masks[x] & m)) continue;
    board[y][x] = i + 1;
    sub_masks[s] |= m;
    row_masks[y] |= m;
    col_masks[x] |= m;
    if (Check(board, idx + 1, yx, sub_masks, row_masks, col_masks)) return true;
    sub_masks[s] ^= m;
    row_masks[y] ^= m;
    col_masks[x] ^= m;
  }

  return false;
}

void Solve() {
  int board[9][9];
  int sub_masks[9] = {};
  int row_masks[9] = {};
  int col_masks[9] = {};
  int yx[5];
  auto it = yx;
  char str[10];
  for (int i = 0; i < 9; i++) {
    cin >> str;
    for (int j = 0; j < 9; j++) {
      board[i][j] = str[j] - '0';
      if (board[i][j]) {
        int m = (1 << (board[i][j] - 1));
        int s = i - i % 3 + j / 3;
        sub_masks[s] |= m;
        row_masks[i] |= m;
        col_masks[j] |= m;
      } else {
        *it++ = (i << 16) | j;
      }
    }
  }

  if (Check(board, 0, yx, sub_masks, row_masks, col_masks)) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) cout << board[i][j];
      cout << "\n";
    }
  } else {
    cout << "Could not complete this grid.\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    Solve();
    if (t) cout << "\n";
  }

  return 0;
}
