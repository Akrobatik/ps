// Title : 학교 가지마!
// Link  : https://www.acmicpc.net/problem/1420 
// Time  : 4 ms
// Memory: 4424 KB

#include <bits/stdc++.h>

using namespace std;

struct Dinic {
 private:
  using Edge = tuple<int, int64_t, int64_t>;

 public:
  void Init(int n) {
    edges.clear();
    graph.assign(n, {});
    lv.assign(n, 0);
    memo.resize(n);
  }

  void AddEdge(int u, int v, int64_t cap) {
    int idx = edges.size();
    edges.push_back({v, cap, 0});
    edges.push_back({u, 0, 0});
    graph[u].push_back(idx++);
    graph[v].push_back(idx++);
  }

  int64_t Solve(int s, int t) {
    int64_t res = 0;
    while (BFS(s, t)) {
      fill(memo.begin(), memo.end(), 0);
      while (int64_t f = DFS(s, t, kFlowInf)) res += f;
    }
    return res;
  }

 private:
  const int64_t kFlowInf = numeric_limits<int64_t>::max() >> 1;

  bool BFS(int s, int t) {
    fill(lv.begin(), lv.end(), -1);
    lv[s] = 0;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto id : graph[u]) {
        auto [v, c, f] = edges[id];
        if (c == f || lv[v] != -1) continue;
        lv[v] = lv[u] + 1;
        q.push(v);
      }
    }
    return lv[t] != -1;
  }

  int64_t DFS(int u, int t, int64_t pushed) {
    if (u == t || pushed == 0) return pushed;

    for (auto& i = memo[u]; i < graph[u].size(); i++) {
      int id = graph[u][i];
      auto& [v, c, f] = edges[id];
      if (lv[u] + 1 != lv[v]) continue;

      int64_t add = DFS(v, t, min<int64_t>(pushed, c - f));
      if (add == 0) continue;

      f += add;
      get<2>(edges[id ^ 1]) -= add;
      return add;
    }
    return 0;
  }

  vector<Edge> edges;
  vector<vector<int>> graph;
  vector<int> lv, memo;
  queue<int> q;
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

  Dinic solver;
  solver.Init(n * m * 2);

  int pad = n * m;
  int ky, kx, hy, hx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '#') continue;
      if (board[i][j] == 'K') ky = i, kx = j;
      if (board[i][j] == 'H') hy = i, hx = j;

      int u = i * m + j, v = u + pad;
      solver.AddEdge(u, v, 1);

      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (0 <= y && y < n && 0 <= x && x < m && board[y][x] != '#') {
          solver.AddEdge(v, y * m + x, 1);
        }
      }
    }
  }

  if (abs(ky - hy) + abs(kx - hx) == 1) {
    cout << "-1";
  } else {
    cout << solver.Solve(ky * m + kx + pad, hy * m + hx);
  }

  return 0;
}
