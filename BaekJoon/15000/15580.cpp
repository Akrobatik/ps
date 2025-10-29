// Title : Clickbait
// Link  : https://www.acmicpc.net/problem/15580 
// Time  : 12 ms
// Memory: 8200 KB

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

  auto IsDigit = [&](int y, int x) {
    return '0' <= board[y][x] && board[y][x] <= '9';
  };

  vector<vector<int>> memo(n, vector<int>(m));
  queue<pair<int, int>> q;

  auto Push = [&](int y, int x, int t) {
    if (memo[y][x] || (!IsDigit(y, x) && board[y][x] != '.')) return;
    memo[y][x] = t;
    q.push({y, x});
  };

  int maxx = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (IsDigit(i, j) && !IsDigit(i, j - 1)) {
        string num;
        int y = i, x = j;
        while (x < m && IsDigit(y, x)) num.push_back(board[y][x++]);

        int v = stoi(num);
        maxx = max<int>(maxx, v);

        Push(i, j, v);
        while (!q.empty()) {
          auto [yy, xx] = q.front();
          q.pop();

          for (auto [dy, dx] : kDelta) {
            Push(yy + dy, xx + dx, v);
          }
        }
      }
    }
  }

  vector<vector<pair<int, int>>> units(maxx + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v = memo[i][j];
      if (v == 0) continue;

      units[v].push_back({i, j});
    }
  }

  vector<vector<int>> g(maxx + 1);
  for (int i = 1; i <= maxx; i++) {
    sort(units[i].begin(), units[i].end(), greater<pair<int, int>>());
    for (auto [y, x] : units[i]) {
      for (int dx : {-2, 2}) {
        int yy = y, xx = x + dx;
        if (0 <= xx && xx < m && board[yy][xx] == '-') {
          int oy = y, ox = x + dx / 2;
          int cy = y, cx = x + dx;
          for (;;) {
            bool ok = false;
            for (auto [dyy, dxx] : kDelta) {
              int ny = cy + dyy, nx = cx + dxx;
              if (ny == oy && nx == ox) continue;
              if (!(0 <= ny && ny < n && 0 <= nx && nx < m)) continue;
              if (board[ny][nx] != '-' && board[ny][nx] != '|' && board[ny][nx] != '+') continue;

              if (board[cy][cx] == '-' && dyy != 0) continue;
              if (board[cy][cx] == '|' && dxx != 0) continue;

              if (board[ny][nx] == '-' && dyy != 0) continue;
              if (board[ny][nx] == '|' && dxx != 0) continue;

              ok = true;
              oy = cy, ox = cx, cy = ny, cx = nx;
              break;
            }

            if (!ok) break;
          }

          int nxt = memo[cy + 2][cx];
          g[i].push_back(nxt);
        }
      }
    }
  }

  [&](this auto&& self, int cur) -> void {
    for (auto nxt : g[cur]) {
      self(nxt);
    }
    cout << cur << "\n";
  }(1);

  return 0;
}