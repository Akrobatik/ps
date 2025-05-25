// Title : 사각형 모험
// Link  : https://www.acmicpc.net/problem/33951 
// Time  : 216 ms
// Memory: 37720 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<string> board(n);
  for (auto& s : board) cin >> s;

  vector<vector<int>> minn(n, vector<int>(m)), maxx(n, vector<int>(m));

  minn[0][0] = maxx[0][0] = (board[0][0] == 'A');
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) continue;
      int mn = INT_MAX >> 1, mx = 0;
      int add = (board[i][j] == 'A');
      if (i != 0) {
        mn = min<int>(mn, minn[i - 1][j] + add);
        mx = max<int>(mx, maxx[i - 1][j] + add);
      }
      if (j != 0) {
        mn = min<int>(mn, minn[i][j - 1] + add);
        mx = max<int>(mx, maxx[i][j - 1] + add);
      }
      minn[i][j] = mn, maxx[i][j] = mx;
    }
  }

  int mn = minn[n - 1][m - 1], mx = maxx[n - 1][m - 1];
  while (k--) {
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t d = b - a;
    int64_t x = a * (n + m - 1);
    if (d == 0) {
      if (x == c) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      if ((c - x) % d == 0) {
        int64_t y = (n + m - 1) - (c - x) / d;
        if (mn <= y && y <= mx) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}