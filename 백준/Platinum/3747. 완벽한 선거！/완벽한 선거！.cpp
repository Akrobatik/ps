#include <bits/stdc++.h>

using namespace std;

struct TwoSAT {
  void Init(int n) {
    idx = 0;
    edges.clear(), edges.resize(n << 1);
    orders.clear(), orders.resize(n << 1);
    scc_ids.clear(), scc_ids.resize(n << 1);
    stk.clear();
    results.clear(), results.resize(n, -1);
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  void AddCNF(int a, int b) {
    edges[a ^ 1].push_back(b);
    edges[b ^ 1].push_back(a);
  }

  bool Solve() {
    int n = scc_ids.size();
    for (int i = 0; i < n; i++) {
      if (!scc_ids[i]) DFS(i);
    }
    for (int i = 0; i < n; i += 2) {
      if (scc_ids[i] == scc_ids[i + 1]) return false;
    }
    return true;
  }

  int idx;
  vector<vector<int>> edges;
  vector<int> orders, scc_ids, stk;
  vector<int> results;

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
      do {
        child = stk.back();
        stk.pop_back();
        scc_ids[child] = low;
        if (results[child >> 1] == -1) results[child >> 1] = (child ^ 1) & 1;
      } while (u != child);
    }
    return orders[u] = low;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  TwoSAT solver;
  int n, m;
  while (cin >> n >> m) {
    solver.Init(n);
    while (m--) {
      int a, b;
      char sa, sb;
      cin >> sa >> a >> sb >> b;
      a = (a - 1) << 1, b = (b - 1) << 1;
      if (sa == '+') {
        if (sb == '+') {
          solver.AddCNF(a, b);
        } else {
          solver.AddCNF(a, b ^ 1);
        }
      } else {
        if (sb == '+') {
          solver.AddCNF(a ^ 1, b);
        } else {
          solver.AddCNF(a ^ 1, b ^ 1);
        }
      }
    }

    cout << (solver.Solve() ? "1\n" : "0\n");
  }

  return 0;
}
