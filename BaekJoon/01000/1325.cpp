// Title : 효율적인 해킹
// Link  : https://www.acmicpc.net/problem/1325 
// Time  : 44 ms
// Memory: 17652 KB

#include <bits/stdc++.h>

using namespace std;

struct SCC {
  void Init(int n) {
    idx = scc_cnt = 0;
    edges.clear(), edges.resize(n);
    orders.clear(), orders.resize(n);
    scc_ids.clear(), scc_ids.resize(n);
    stk.clear();
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  int Solve() {
    int n = scc_ids.size();
    for (int i = 0; i < n; i++) {
      if (!scc_ids[i]) DFS(i);
    }
    return scc_cnt;
  }

  int idx, scc_cnt;
  vector<vector<int>> edges;
  vector<int> orders, scc_ids, stk;

 private:
  int DFS(int u) {
    int low = orders[u] = ++idx;
    stk.push_back(u);

    for (auto v : edges[u]) {
      if (scc_ids[v]) continue;
      low = min<int>(low, orders[v] ? orders[v] : DFS(v));
    }

    if (orders[u] == low) {  // Root
      int child;
      ++scc_cnt;
      do {
        child = stk.back();
        stk.pop_back();
        scc_ids[child] = scc_cnt;
      } while (u != child);
    }
    return orders[u] = low;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  SCC solver;
  solver.Init(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    solver.AddEdge(b - 1, a - 1);
  }

  int ng = solver.Solve();
  auto& scc = solver.scc_ids;

  vector<bitset<10000>> memo(ng);
  vector<vector<int>> groups(ng);
  for (int i = 0; i < n; i++) {
    groups[scc[i] - 1].push_back(i);
    memo[scc[i] - 1].set(i);
  }

  vector<vector<int>> edges(ng);
  vector<int> deg(ng);
  for (int i = 0; i < ng; i++) {
    bool visited[10000] = {};
    visited[i] = true;
    for (auto gi : groups[i]) {
      for (auto nxt : solver.edges[gi]) {
        int j = scc[nxt] - 1;
        if (visited[j]) continue;
        visited[j] = true;
        edges[i].push_back(j);
        ++deg[j];
      }
    }
  }

  queue<int> q;
  for (int i = 0; i < ng; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  vector<int> orders;
  orders.reserve(ng);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    orders.push_back(cur);
    for (auto nxt : edges[cur]) {
      if (--deg[nxt] == 0) q.push(nxt);
    }
  }

  for (auto id : views::reverse(orders)) {
    auto& bits = memo[id];
    for (auto nxt : edges[id]) bits |= memo[nxt];
  }

  vector<pair<int, int>> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = {memo[scc[i] - 1].count(), i + 1};
  }

  sort(ans.begin(), ans.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [lc, li] = lhs;
    auto [rc, ri] = rhs;
    return lc > rc || (lc == rc && li < ri);
  });

  int maxx = ans[0].first;
  for (auto [c, i] : ans) {
    if (maxx != c) break;
    cout << i << " ";
  }

  return 0;
}