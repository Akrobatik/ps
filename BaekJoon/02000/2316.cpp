// Title : 도시 왕복하기 2
// Link  : https://www.acmicpc.net/problem/2316 
// Time  : 12 ms
// Memory: 3348 KB

#include <bits/stdc++.h>

using namespace std;

struct MCMF {
 public:
  using Cap = int;
  using Cost = int;
  using Edge = tuple<int, int, Cap, Cost>;

  const Cap kCapInf = numeric_limits<Cap>::max() >> 1;
  const Cost kCostInf = numeric_limits<Cost>::max() >> 1;

  MCMF(int _n) : n(_n), edges(_n), dual(_n), dist(_n), pv(_n), pe(_n), vis(_n) {}

  void AddEdge(int u, int v, Cap cap, Cost cost) {
    int uid = edges[u].size(), vid = edges[v].size();
    edges[u].push_back({v, vid, cap, cost});
    edges[v].push_back({u, uid, 0, -cost});
  }

  pair<Cap, Cost> Solve(int s, int t, Cap limit = -1) {
    dual.assign(n, 0);

    if (limit < 0) limit = kCapInf;

    Cap flow = 0;
    Cost cost = 0, cpf = -1;
    vector<pair<Cap, Cost>> his{make_pair(flow, cost)};
    while (flow < limit && Update(s, t)) {
      Cap add = limit - flow;

      for (int v = t; v != s; v = pv[v]) {
        add = min<Cap>(add, get<2>(edges[pv[v]][pe[v]]));
      }

      for (int v = t; v != s; v = pv[v]) {
        auto& [_, u, cap, __] = edges[pv[v]][pe[v]];
        cap -= add;
        get<2>(edges[v][u]) += add;
      }

      Cost d = -dual[s];
      flow += add;
      cost += d * add;
      if (cpf == d) his.pop_back();
      his.push_back({flow, cost});
      cpf = d;
    }
    return his.back();
  }

 private:
  bool Update(int s, int t) {
    dist.assign(n, kCostInf);
    pv.assign(n, -1);
    pe.assign(n, -1);
    vis.assign(n, false);

    priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();

      if (vis[u]) continue;
      vis[u] = true;

      if (u == t) break;

      for (int i = 0; i < edges[u].size(); i++) {
        auto [v, rev, cap, cost] = edges[u][i];

        if (vis[v] || cap == 0 || dist[v] <= dist[u] + dual[u] - dual[v] + cost) continue;

        dist[v] = dist[u] + dual[u] - dual[v] + cost;
        pv[v] = u;
        pe[v] = i;
        pq.push({dist[v], v});
      }
    }

    if (!vis[t]) return false;

    for (int i = 0; i < n; i++) {
      if (vis[i]) dual[i] -= dist[t] - dist[i];
    }
    return true;
  }

  int n;
  vector<vector<Edge>> edges;
  vector<Cost> dual, dist;
  vector<int> pv, pe;
  vector<bool> vis;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  MCMF mcmf(n << 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    mcmf.AddEdge(a - 1, n + b - 1, 1, 0);
    mcmf.AddEdge(b - 1, n + a - 1, 1, 0);
  }

  for (int i = 0; i < n; i++) {
    mcmf.AddEdge(n + i, i , 1, 0);
  }

  auto [flow, cost] = mcmf.Solve(0, n + 1);
  cout << flow;

  return 0;
}
