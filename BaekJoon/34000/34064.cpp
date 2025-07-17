// Title : 밤(Time For The Moon Night)
// Link  : https://www.acmicpc.net/problem/34064 
// Time  : 20 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<bool>> board(n + 2, vector<bool>(m + 2));
  for (int i = 0; i <= n + 1; i++) {
    board[i][0] = board[i][m + 1] = true;
  }
  for (int i = 0; i <= m + 1; i++) {
    board[0][i] = board[n + 1][i] = true;
  }
  while (k--) {
    int y, x;
    cin >> y >> x;
    board[y][x] = true;
  }

  pair<int, int> ab[4];
  for (auto& [a, b] : ab) {
    cin >> a >> b;
  }

  auto CheckA = [&](int y, int x) {
    auto [y1, x1] = ab[0];
    auto [y2, x2] = ab[1];
    return y1 <= y && y <= y2 && x1 <= x && x <= x2;
  };

  auto CheckB = [&](int y, int x) {
    auto [y1, x1] = ab[2];
    auto [y2, x2] = ab[3];
    return y1 <= y && y <= y2 && x1 <= x && x <= x2;
  };

  queue<pair<int, int>> q;

  auto Push = [&](int y, int x) {
    if (board[y][x]) return;
    board[y][x] = true;
    q.push({y, x});
  };

  int64_t ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j]) continue;

      int c1 = 0, c2 = 0;
      Push(i, j);
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        c1 += CheckA(y, x);
        c2 += CheckB(y, x);
        for (auto [dy, dx] : kDelta) {
          Push(y + dy, x + dx);
        }
      }
      ans += (int64_t)c1 * c2;
    }
  }
  cout << ans;

  return 0;
}
