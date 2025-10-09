// Title : 다리 만들기 2
// Link  : https://www.acmicpc.net/problem/17472 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> board(n, vector<int>(m));
  for (auto& vec : board) {
    for (auto& e : vec) {
      cin >> e;
    }
  }

  vector<int> memo(n * m);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  auto Check = [&](int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
  };

  int cnt = 0;
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0 || vis[i][j]) continue;

      ++cnt;

      int id = i * m + j;
      queue<pair<int, int>> q;

      auto Push = [&](int y, int x) {
        if (!Check(y, x) || board[y][x] == 0 || vis[y][x]) return;
        vis[y][x] = true;
        q.push({y, x});
        Union(id, y * m + x);
      };

      Push(i, j);
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          Push(y + dy, x + dx);
        }
      }
    }
  }

  vector<tuple<int, int, int>> adj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) continue;

      int id = Find(i * m + j);
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        while (Check(y, x) && board[y][x] == 0) y += dy, x += dx;

        if (Check(y, x)) {
          int jd = Find(y * m + x);
          int dist = abs(i - y) + abs(j - x) - 1;
          if (id != jd && dist >= 2) adj.push_back({dist, id, jd});
        }
      }
    }
  }
  sort(adj.begin(), adj.end());

  int sum = 0;
  for (auto [w, u, v] : adj) {
    if (Union(u, v)) sum += w, --cnt;
  }

  cout << (cnt == 1 ? sum : -1);

  return 0;
}