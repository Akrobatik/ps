// Title : 트리 복제
// Link  : https://www.acmicpc.net/problem/35418 
// Time  : 60 ms
// Memory: 15440 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> par(n + 1);

  auto DFS = [&](this auto&& self, int u, int p, int d) -> pair<int, int> {
    par[u] = p;

    pair<int, int> res{d, u};
    for (auto v : g[u]) {
      if (v == p) continue;

      auto pr = self(v, u, d + 1);
      res = max<pair<int, int>>(res, pr);
    }
    return res;
  };

  int rt = DFS(1, 0, 0).second;
  int cur = DFS(rt, 0, 0).second;

  vector<int> mst;
  do {
    mst.push_back(cur);
    cur = par[cur];
  } while (cur);

  int nm = mst.size();
  int mid = (nm - 1) >> 1;
  vector<int8_t> mask(n + 1);

  if (nm & 1) {
    for (auto e : mst) mask[e] = 1;
  } else {
    mask[mst[mid + 1]] = 1;
  }

  int idx = 0;
  vector<pair<int, int>> ans;
  vector<int> ids(n + 1);

  [&](this auto&& self, int u, int p) -> void {
    ids[u] = ++idx;
    for (auto v : g[u]) {
      if (v == p || mask[v]) continue;
      self(v, u);
      ans.push_back({ids[u], ids[v]});
    }
  }(mst[mid], 0);

  cout << n / idx << "\n"
       << idx << "\n";
  for (auto [a, b] : ans) cout << a << " " << b << "\n";

  return 0;
}