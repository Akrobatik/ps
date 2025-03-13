#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

char board[100][100];
bool visited[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>> q;
  visited[0][0] = true;
  q.push({0, 0});
  int ans = INT_MAX;
  bool out = false;
  for (int i = 0; !out && !q.empty() && i <= t; i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      if (board[y][x] == '2') {
        int tt = i + n + m - y - x - 2;
        if (tt <= t) ans = min<int>(ans, tt);
      }

      if (y + 1 == n && x + 1 == m) {
        ans = min<int>(ans, i);
        out = true;
        break;
      }

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && !visited[yy][xx] && board[yy][xx] != '1') {
          visited[yy][xx] = true;
          q.push({yy, xx});
        }
      }
    }
  }

  if (ans != INT_MAX) {
    cout << ans;
  } else {
    cout << "Fail";
  }

  return 0;
}
