// Title : 백조의 호수
// Link  : https://www.acmicpc.net/problem/3197 
// Time  : 216 ms
// Memory: 106316 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/dsu.cpp
struct DSU {
  void Init(int n) {
    memo.resize(n);
    iota(memo.begin(), memo.end(), 0);
    sz.assign(n, 1);
    stk.clear();
  }

  int Find(int id) {
    while (id != memo[id]) id = memo[id];
    return id;
  }

  bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    stk.push_back({a, b, sz[a], memo[b]});
    memo[b] = a;
    sz[a] += sz[b];
    return true;
  }

  int Checkpoint() {
    return stk.size();
  }

  void Rollback(int cnt) {
    while (stk.size() > cnt) {
      auto [a, b, sa, mb] = stk.back();
      stk.pop_back();
      memo[b] = mb;
      sz[a] = sa;
    }
  }

 private:
  vector<int> memo, sz;
  vector<tuple<int, int, int, int>> stk;
};

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> board(n);
  for (auto& s : board) cin >> s;

  int sidx = 0;
  pair<int, int> swan[2];

  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  vector<vector<pair<int, int>>> groups(n + m);

  auto Push = [&](int y, int x, int d) {
    if (!(0 <= y && y < n && 0 <= x && x < m) || dist[y][x] <= d) return;
    dist[y][x] = d;
    groups[d].push_back({y, x});
    q.push({y, x});
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'X') continue;
      if (board[i][j] == 'L') swan[sidx++] = {i, j};
      board[i][j] = 0;
      Push(i, j, 0);
    }
  }

  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : kDelta) {
        Push(y + dy, x + dx, i);
      }
    }
  }

  auto Idx = [&](int y, int x) {
    return y * m + x;
  };

  DSU dsu;
  dsu.Init(n * m);

  int si1 = Idx(swan[0].first, swan[0].second);
  int si2 = Idx(swan[1].first, swan[1].second);
  for (int i = 0; i < n + m; i++) {
    for (auto [y, x] : groups[i]) {
      int src = Idx(y, x);
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && dist[yy][xx] <= i) {
          dsu.Union(src, Idx(yy, xx));
        }
      }
    }

    if (dsu.Find(si1) == dsu.Find(si2)) {
      cout << i;
      break;
    }
  }

  return 0;
}