// Title : 숭고한 마법학교
// Link  : https://www.acmicpc.net/problem/34218 
// Time  : 84 ms
// Memory: 7876 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
    }
  }

  int by, bx, ey, ex;
  cin >> by >> bx >> ey >> ex;

  auto Color = [&](int sy, int sx, int cr) {
    queue<pair<int, int>> q;
    board[sy][sx] = cr;
    q.push({sy, sx});
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (1 <= yy && yy <= n && 1 <= xx && xx <= m && board[yy][xx] == 1) {
          board[yy][xx] = cr;
          q.push({yy, xx});
        }
      }
    }
  };

  Color(by, bx, 2);
  if (board[ey][ex] == 2) {
    cout << "0";
    return 0;
  }

  Color(ey, ex, 3);

  queue<pair<int, int>> q;
  vector<vector<bool>> visited(n + 1, vector<bool>(m + 1));

  auto Push = [&](int y, int x) {
    if (!(1 <= y && y <= n && 1 <= x && x <= m) || visited[y][x]) return;
    visited[y][x] = true;
    q.push({y, x});
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j] != 2) continue;
      Push(i, j);
    }
  }

  for (int i = 0; !q.empty(); i++) {
    bool ok = false;

    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      ok |= (board[y][x] == 3);

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx);
      }
    }

    if (ok) {
      cout << i;
      break;
    }
  }

  return 0;
}
