// Title : 목장 건설하기
// Link  : https://www.acmicpc.net/problem/14925 
// Time  : 60 ms
// Memory: 5996 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> board(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x;
      cin >> x;
      board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + x;
    }
  }

  auto Check = [&](int x) {
    for (int i = x; i <= n; i++) {
      for (int j = x; j <= m; j++) {
        int cur = board[i][j] - board[i][j - x] - board[i - x][j] + board[i - x][j - x];
        if (cur == 0) return true;
      }
    }
    return false;
  };

  int lo = 0, hi = min<int>(n, m) + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo;

  return 0;
}
