// Title : 도미노 게임
// Link  : https://www.acmicpc.net/problem/34053 
// Time  : 132 ms
// Memory: 5944 KB

#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(board, 0x7f, sizeof(board));

  int n, m;
  cin >> n >> m;
  int64_t sum = 0;
  int minn = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      sum += board[i][j];
      minn = min<int>({minn, board[i][j], board[i - 1][j], board[i][j - 1]});
    }
  }
  cout << sum - minn;

  return 0;
}
