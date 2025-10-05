// Title : Puyo Puyo
// Link  : https://www.acmicpc.net/problem/11559 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> board(12);
  for (auto& s : board) cin >> s;

  int n = 12, m = 6, cnt = 0;
  for (;;) {
    bool ok = false;
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<pair<int, int>> stk;
    queue<pair<int, int>> q;

    auto Push = [&](int y, int x, char key) {
      if (!(0 <= y && y < n && 0 <= x && x < m) || vis[y][x] || board[y][x] != key) return;
      vis[y][x] = true;
      stk.push_back({y, x});
      q.push({y, x});
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] || board[i][j] == '.') continue;

        char key = board[i][j];
        Push(i, j, key);
        while (!q.empty()) {
          auto [y, x] = q.front();
          q.pop();

          for (auto [dy, dx] : kDelta) {
            Push(y + dy, x + dx, key);
          }
        }

        if (stk.size() < 4) {
          stk.clear();
        } else {
          ok = true;
          while (!stk.empty()) {
            auto [y, x] = stk.back();
            stk.pop_back();

            board[y][x] = '.';
          }
        }
      }
    }

    if (!ok) break;
    ++cnt;

    for (int j = 0; j < 6; j++) {
      vector<char> ord;
      for (int i = n - 1; i >= 0; i--) {
        if (board[i][j] == '.') continue;
        ord.push_back(board[i][j]);
      }

      for (int i = 0; i < n; i++) {
        char ch = (i < ord.size() ? ord[i] : '.');
        board[n - i - 1][j] = ch;
      }
    }
  }
  cout << cnt;

  return 0;
}