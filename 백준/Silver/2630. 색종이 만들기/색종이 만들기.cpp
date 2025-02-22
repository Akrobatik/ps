#include <bits/stdc++.h>

using namespace std;

int board[128][128];
int ans[2];

bool Traverse(int y, int x, int n) {
  int memo[2] = {};
  if (n == 2) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        ++memo[board[y + i][x + j]];
      }
    }
  } else {
    n >>= 1;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        int yy = y + (i ? n : 0), xx = x + (j ? n : 0);
        memo[board[yy][xx]] += Traverse(yy, xx, n);
      }
    }
  }

  if (memo[board[y][x]] ^ 4) {
    ans[0] += memo[0];
    ans[1] += memo[1];
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }

  ans[board[0][0]] += Traverse(0, 0, n);

  cout << ans[0] << "\n"
       << ans[1];

  return 0;
}
