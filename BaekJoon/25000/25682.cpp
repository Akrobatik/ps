// Title : 체스판 다시 칠하기 2
// Link  : https://www.acmicpc.net/problem/25682
// Time  : 60 ms
// Memory: 21568 KB

#include <bits/stdc++.h>

using namespace std;

char board[2000][2000];
int sum[2001][2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  int maxx = k * k;
  int half = maxx >> 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> board[i][j];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (board[i][j] == (((i + j) & 1) ? 'B' : 'W'));
    }
  }

  int ans = INT_MAX;
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      int now = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
      if (now > half) now = maxx - now;
      if (ans > now) ans = now;
    }
  }
  cout << ans;

  return 0;
}
