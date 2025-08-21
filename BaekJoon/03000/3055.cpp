// Title : 탈출
// Link  : https://www.acmicpc.net/problem/3055 
// Time  : 0 ms
// Memory: 2160 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> board(n);
  for (auto& s : board) cin >> s;

  queue<pair<int, int>> q[2];
  vector<vector<bool>> visited(n, vector<bool>(m));

  auto Push = [&](int y, int x, int t) {
    if (!(0 <= y && y < n && 0 <= x && x < m) || visited[y][x] || board[y][x] == 'X' || (t == 0 && board[y][x] == 'D')) return;
    visited[y][x] = true;
    q[t].push({y, x});
  };

  int ty, tx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '*') {
        Push(i, j, 0);
      } else if (board[i][j] == 'S') {
        Push(i, j, 1);
      } else if (board[i][j] == 'D') {
        ty = i, tx = j;
      }
    }
  }

  int dist = 0;
  for (int i = 1; !q[0].empty() || !q[1].empty(); i++) {
    int nq0 = q[0].size(), nq1 = q[1].size();
    while (nq0--) {
      auto [y, x] = q[0].front();
      q[0].pop();

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx, 0);
      }
    }

    while (nq1--) {
      auto [y, x] = q[1].front();
      q[01].pop();

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx, 1);
      }
    }

    if (visited[ty][tx]) {
      dist = i;
      break;
    }
  }

  if (dist) {
    cout << dist;
  } else {
    cout << "KAKTUS";
  }

  return 0;
}