// Title : 가장 큰 정사각형
// Link  : https://www.acmicpc.net/problem/1915 
// Time  : 24 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

int board[1001][1001];

bool Check(int x, int n, int m) {
  int y = x * x;
  for (int i = x; i <= n; i++) {
    for (int j = x; j <= m; j++) {
      int z = board[i][j] - board[i - x][j] - board[i][j - x] + board[i - x][j - x];
      if (y == z) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      board[i][j] = board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1] + (c - '0');
    }
  }

  int lo = 0, hi = min<int>(n, m) + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid, n, m)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << lo * lo;

  return 0;
}
