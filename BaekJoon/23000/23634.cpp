// Title : 미안하다 이거 보여주려고 어그로 끌었다
// Link  : https://www.acmicpc.net/problem/23634 
// Time  : 568 ms
// Memory: 82732 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<int> MakeTable(vector<vector<char>> board, const vector<tuple<int, int, int>>& fires) {
  vector<int> table(fires.size());
  iota(table.begin(), table.end(), 0);

  int n = board.size(), m = board[0].size();
  vector<vector<int>> memo(n, vector<int>(m));

  auto Find = [&](int id) {
    while (id != table[id]) {
      int par = table[id];
      id = table[id] = table[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    table[b] = a;
  };

  queue<pair<int, int>> q;
  for (auto [y, x, fidx] : fires) memo[y][x] = fidx, q.push({y, x});
  while (!q.empty()) {
    auto [y, x] = q.front();
    q.pop();

    int fidx = Find(memo[y][x]);
    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m) {
        if (board[yy][xx] == '0') {
          Union(fidx, memo[yy][xx]);
        } else if (board[yy][xx] == '1') {
          board[yy][xx] = '0';
          memo[yy][xx] = fidx;
          q.push({yy, xx});
        }
      }
    }
  }

  for (auto& e : table) e = Find(e);
  return table;
}

pair<int, int> Solve(vector<vector<char>> board, const vector<tuple<int, int, int>>& fires, const vector<int>& goal) {
  vector<int> table(fires.size());
  iota(table.begin(), table.end(), 0);

  int n = board.size(), m = board[0].size();
  vector<vector<int>> memo(n, vector<int>(m));

  auto Find = [&](int id) {
    while (id != table[id]) {
      int par = table[id];
      id = table[id] = table[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    table[b] = a;
  };

  int cnt = fires.size(), t;
  queue<pair<int, int>> q;
  for (auto [y, x, fidx] : fires) memo[y][x] = fidx, q.push({y, x});
  for (t = 0;; t++) {
    queue<pair<int, int>> q2(q);
    int nq2 = q2.size();
    while (nq2--) {
      auto [y, x] = q2.front();
      q2.pop();

      int fidx = Find(memo[y][x]);
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m) {
          if (board[yy][xx] == '0') {
            Union(fidx, memo[yy][xx]);
          }
        }
      }
    }

    bool ok = true;
    for (int i = 0; ok && i < fires.size(); i++) {
      ok = (Find(i) == goal[i]);
    }
    if (ok) break;

    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      int fidx = Find(memo[y][x]);
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m) {
          if (board[yy][xx] == '0') {
            Union(fidx, memo[yy][xx]);
          } else if (board[yy][xx] == '1') {
            ++cnt;
            board[yy][xx] = '0';
            memo[yy][xx] = fidx;
            q.push({yy, xx});
            q2.push({yy, xx});
          }
        }
      }
    }
  }
  return {t, cnt};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> board(n, vector<char>(m));
  vector<tuple<int, int, int>> fires;
  int fidx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == '0') fires.push_back({i, j, fidx++});
    }
  }

  auto table = MakeTable(board, fires);
  auto [t, cnt] = Solve(board, fires, table);
  cout << t << " " << cnt;

  return 0;
}
