#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int Find(int x) {
  while (x != memo[x]) {
    int par = memo[x];
    x = memo[x] = memo[par];
  }
  return x;
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  memo[a] = b;
}

struct TwoSAT {
  void Init(int n) {
    idx = 0;
    edges.clear(), edges.resize(n);
    orders.clear(), orders.resize(n);
    scc_ids.clear(), scc_ids.resize(n);
    stk.clear();
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
        Union(u, child);
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

  TwoSAT solver;
  solver.Init(n + 1);
  memo.resize(n + 1);
  iota(memo.begin(), memo.end(), 0);
  vector<pair<int, int>> neq, gt, gte;
  while (m--) {
    int a, b;
    string op;
    cin >> a >> op >> b;
    if (op[0] == '<') swap(a, b);
    if (op == "==") {
      solver.AddEdge(a, b);
      solver.AddEdge(b, a);
    } else if (op == "!=") {
      neq.push_back({a, b});
    } else {
      solver.AddEdge(a, b);
      if (op.size() == 1) {
        gt.push_back({a, b});
      } else {
        gte.push_back({a, b});
      }
    }
  }

  solver.Solve();
  for (auto [a, b] : neq) {
    a = Find(a), b = Find(b);
    if (a != b) continue;
    cout << "NO";
    return 0;
  }

  for (auto [a, b] : gte) {
    a = Find(a), b = Find(b);
    if (a == b) continue;
    gt.push_back({a, b});
  }

  vector<unordered_set<int>> edges(n + 1);
  vector<int> deg(n + 1);
  for (auto [a, b] : gt) {
    a = Find(a), b = Find(b);
    if (a == b) {
      cout << "NO";
      return 0;
    }
    if (edges[b].insert(a).second) ++deg[a];
  }

  int nn = 0;
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (i != Find(i)) continue;
    ++nn;
    if (deg[i] == 0) q.push(i);
  }

  int cnt = 0;
  vector<int> ans(n + 1);
  while (!q.empty()) {
    auto id = q.front();
    q.pop();

    ans[id] = ++cnt;
    for (auto nxt : edges[id]) {
      if (--deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  if (cnt == nn) {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[Find(i)] << " ";
    }
  } else {
    cout << "NO";
  }

  return 0;
}
