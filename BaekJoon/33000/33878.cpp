// Title : Лягушки на дереве
// Link  : https://www.acmicpc.net/problem/33878 
// Time  : 812 ms
// Memory: 166056 KB

#pragma GCC optimize("O3,unroll-loops")

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

  int cnt[2] = {};

  [&](this auto&& self, int u, int p, int d) -> void {
    ++cnt[d & 1];
    for (auto v : g[u]) {
      if (v == p) continue;
      self(v, u, d + 1);
    }
  }(1, 0, 0);

  int lmt = min<int>(cnt[0], cnt[1]);

  vector<pair<int, int>> ans;
  vector<int> dist(n + 1), rep(n + 1);
  vector<array<set<pair<int, int>, greater<pair<int, int>>>, 2>> memo(n + 1);

  auto Get = [&](int u, int v) {
    int du = dist[u], dv = dist[v];
    return max<int>((du + dv - bnd) / 2, 0);
  };

  auto Match = [&](int x) {
    int swp = (memo[x][0].size() > memo[x][1].size());
    auto& m1 = memo[x][swp];
    auto& m2 = memo[x][swp ^ 1];

    int rbnd = bnd + dist[x] * 2;

    auto it = m1.begin();
    while (it != m1.end()) {
      auto jt = m2.lower_bound({rbnd - it->first, INT_MAX});
      if (jt != m2.end()) {
        int u = it->second, v = jt->second;
        int tgt = rep[Get(u, v)];
        if (tgt == x) {
          --lmt;
          ans.push_back({u, v});
          it = m1.erase(it);
          jt = m2.erase(jt);
          continue;
        }
      }
      ++it;
    }
  };

  [&](this auto&& self, int u, int p, int d) -> void {
    dist[u] = d, rep[d] = u;

    for (auto v : g[u]) {
      if (v == p) continue;

      self(v, u, d + 1);

      for (int i = 0; i < 2; i++) {
        auto& mv = memo[v][i];
        auto it = mv.begin();
        while (it != mv.end() && it->first - d > bnd) it = mv.erase(it);

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
  }(1, 0, 0);

  cout << ans.size() << "\n";
  for (auto [u, v] : ans) cout << u << " " << v << "\n";

  return 0;
}