// Title : 지정좌석제
// Link  : https://www.acmicpc.net/problem/33993 
// Time  : 256 ms
// Memory: 197844 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, c, w;
  cin >> n >> r >> c >> w;

  vector<vector<int>> board(r + 1, vector<int>(c + 1));
  while (n--) {
    int y, x;
    cin >> y >> x;
    board[y][x] = 1;
  }

  vector<vector<int>> memo(r + 1, vector<int>(c + 1));
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + board[i][j];
    }
  }

  int half = w >> 1;
  int maxx = -1, by, bx;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (board[i][j]) continue;
      int y1 = max<int>(i - half - 1, 0), y2 = min<int>(i + half, r);
      int x1 = max<int>(j - half - 1, 0), x2 = min<int>(j + half, c);
      int cur = memo[y2][x2] - memo[y2][x1] - memo[y1][x2] + memo[y1][x1];
      if (maxx < cur) maxx = cur, by = i, bx = j;
    }
  }

  cout << maxx << "\n"
       << by << " " << bx;

  return 0;
}
