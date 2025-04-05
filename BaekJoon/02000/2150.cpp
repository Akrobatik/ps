// Title : Strongly Connected Component
// Link  : https://www.acmicpc.net/problem/2150
// Time  : 20 ms
// Memory: 9596 KB

#include <bits/stdc++.h>

using namespace std;

struct TwoSAT {
  void Init(int n) {
    idx = 0;
    edges.clear(), edges.resize(n);
    orders.clear(), orders.resize(n);
    scc_ids.clear(), scc_ids.resize(n);
    stk.clear();
    results.clear();
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  void AddCNF(int a, int b) {
    edges[a ^ 1].push_back(b);
    edges[b ^ 1].push_back(a);
  }

  void Solve() {
    int n = scc_ids.size();
    for (int i = 0; i < n; i++) {
      if (!scc_ids[i]) DFS(i);
    }
  }

  int idx;
  vector<vector<int>> edges;
  vector<int> orders, scc_ids, stk;
  vector<vector<int>> results;

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
      auto& group = results.emplace_back();
      group.reserve(stk.size());
      do {
        child = stk.back();
        stk.pop_back();
        scc_ids[child] = low;
        group.push_back(child);
      } while (u != child);
    }
    return orders[u] = low;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  TwoSAT solver;
  int v, e;
  cin >> v >> e;
  solver.Init(v);
  while (e--) {
    int u, v;
    cin >> u >> v;
    solver.AddEdge(u - 1, v - 1);
  }
  solver.Solve();

  for (auto& group : solver.results) sort(group.begin(), group.end());
  sort(solver.results.begin(), solver.results.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
    return lhs.front() < rhs.front();
  });

  cout << solver.results.size() << "\n";
  for (auto& group : solver.results) {
    for (auto v : group) cout << v + 1 << " ";
    cout << "-1\n";
  }

  return 0;
}
