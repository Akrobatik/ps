// Title : 최장 최장 증가 부분 수열
// Link  : https://www.acmicpc.net/problem/25343 
// Time  : 68 ms
// Memory: 2152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> board(n, vector<int>(n));
  for (auto& vec : board) {
    for (auto& e : vec) cin >> e;
  }

  vector<vector<int>> memo(n, vector<int>(n));
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = board[i][j], cur = 0;
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
          if (x <= board[k][l]) continue;
          cur = max<int>(cur, memo[k][l]);
        }
      }
      memo[i][j] = cur + 1;
      maxx = max<int>(maxx, memo[i][j]);
    }
  }
  cout << maxx;

  return 0;
}
