// Title : TV Show Game
// Link  : https://www.acmicpc.net/problem/16367 
// Time  : 8 ms
// Memory: 2996 KB

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

  int k, n;
  cin >> k >> n;

  TwoSAT solver;
  solver.Init(k);

  while (n--) {
    int a, b, c;
    char aa, bb, cc;
    cin >> a >> aa >> b >> bb >> c >> cc;
    a = ((a - 1) << 1) + (aa == 'B');
    b = ((b - 1) << 1) + (bb == 'B');
    c = ((c - 1) << 1) + (cc == 'B');
    solver.AddEdge(a, b ^ 1);
    solver.AddEdge(a, c ^ 1);
    solver.AddEdge(b, a ^ 1);
    solver.AddEdge(b, c ^ 1);
    solver.AddEdge(c, a ^ 1);
    solver.AddEdge(c, b ^ 1);
  }

  if (solver.Solve()) {
    string s;
    s.reserve(k);
    for (auto e : solver.results) {
      s.push_back(e ? 'B' : 'R');
    }
    cout << s;
  } else {
    cout << "-1";
  }

  return 0;
}
