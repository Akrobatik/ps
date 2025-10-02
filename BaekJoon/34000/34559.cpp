// Title : 건물 측량
// Link  : https://www.acmicpc.net/problem/34559 
// Time  : 84 ms
// Memory: 7216 KB

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

  queue<pair<int, int>> q;
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));

  auto Push = [&](int y, int x) {
    if (!(1 <= y && y <= n && 1 <= x && x <= m) || board[y - 1][x - 1] == '1' || vis[y][x]) return;
    vis[y][x] = true;
    q.push({y, x});
  };

  for (int i = 1; i <= n; i++) Push(i, 1), Push(i, m);
  for (int i = 1; i <= m; i++) Push(1, i), Push(n, i);

  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    for (auto [dy, dx] : kDelta) {
      Push(y + dy, x + dx);
    }
  }

  vector<vector<int>> memo(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + (board[i - 1][j - 1] == '1' || !vis[i][j]);
    }
  }

  int qq;
  cin >> qq;
  while (qq--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    --x1, --y1;

    int cnt = memo[y2][x2] - memo[y2][x1] - memo[y1][x2] + memo[y1][x1];
    if (cnt == 0) {
      cout << "Yes\n";
    } else {
      cout << "No " << cnt << "\n";
    }
  }

  return 0;
}