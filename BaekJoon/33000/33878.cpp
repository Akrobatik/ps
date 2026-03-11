// Title : Лягушки на дереве
// Link  : https://www.acmicpc.net/problem/33878 
// Time  : 456 ms
// Memory: 89668 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, bnd;
  cin >> n >> bnd;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> par(n + 1), dist(n + 1), deg(n + 1);

  [&](this auto&& self, int u, int p, int d) -> void {
    par[u] = p, dist[u] = d, deg[u] = g[u].size() - (p != 0);
    for (auto v : g[u]) {
      if (v == p) continue;
      self(v, u, d + 1);
    }
  }(1, 0, 0);

  int cnt[2] = {};
  for (int i = 1; i <= n; i++) {
    ++cnt[dist[i] & 1];
  }

  int lmt = min<int>(cnt[0], cnt[1]);

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  vector<pair<int, int>> ans;
  vector<array<set<pair<int, int>, greater<pair<int, int>>>, 2>> memo(n + 1);

  auto Match = [&](int x) {
    int swp = (memo[x][0].size() > memo[x][1].size());
    auto& m1 = memo[x][swp];
    auto& m2 = memo[x][swp ^ 1];

    int rbnd = bnd + dist[x] * 2;

    auto it = m1.begin();
    while (it != m1.end()) {
      auto jt = m2.lower_bound({rbnd - it->first, INT_MAX});
      if (jt == m2.end()) {
        ++it;
      } else {
        ans.push_back({it->second, jt->second});
        it = m1.erase(it);
        m2.erase(jt);

        --lmt;
      }
    }
  };

  auto Out = [&](int u, int i, int base) {
    auto& m = memo[u][i];
    auto it = m.begin();
    while (it != m.end() && it->first - base > bnd) it = m.erase(it);
  };

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int p = par[u], d = dist[u];
    if (--deg[p] == 0) q.push(p);

    for (int i = 0; i < 2; i++) {
      for (auto v : g[u]) {
        if (v == p) continue;

        Out(v, i, d);
        if (memo[u][i].size() < memo[v][i].size()) {
          swap(memo[u][i], memo[v][i]);
          while (memo[u][i].size() > lmt) memo[u][i].erase(memo[u][i].begin());
        }

        for (auto pr : memo[v][i]) {
          memo[u][i].insert(pr);
          if (memo[u][i].size() > lmt) memo[u][i].erase(memo[u][i].begin());
        }
      }
    }

    memo[u][d & 1].insert({d, u});
    if (memo[u][d & 1].size() > lmt) memo[u][d & 1].erase(memo[u][d & 1].begin());

    Match(u);
  }

  cout << ans.size() << "\n";
  for (auto [u, v] : ans) cout << u << " " << v << "\n";

  return 0;
}