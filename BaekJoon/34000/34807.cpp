// Title : 비밀 작전
// Link  : https://www.acmicpc.net/problem/34807 
// Time  : 108 ms
// Memory: 4768 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, x;
  cin >> n >> m >> x;

  vector<int64_t> val(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  vector<pair<int, int>> adj(m);
  for (auto& [u, v] : adj) {
    cin >> u >> v;
    if (val[u] > val[v]) swap(u, v);
  }

  int q;
  cin >> q;
  vector<int> out(n + 1, q);
  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    out[v] = i;
  }

  sort(adj.begin(), adj.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [lu, lv] = lhs;
    auto [ru, rv] = rhs;
    return val[lu] > val[ru];
  });

  vector<int> memo, sz;

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    sz[a] += sz[b];
    return true;
  };

  auto Check = [&](int bnd) {
    for (int i = 1; i <= n; i++) {
      if (val[i] == x && out[i] >= bnd) {
        return true;
      }
    }

    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);
    sz.assign(n + 1, 1);

    int idx = 0;
    while (idx < m) {
      int64_t cur = val[adj[idx].first];
      int nxt = idx;
      while (nxt < m && cur == val[adj[nxt].first]) ++nxt;

      for (int i = idx; i < nxt; i++) {
        auto [u, v] = adj[i];
        if (out[u] >= bnd && out[v] >= bnd) {
          if (Union(u, v)) {
            int usz = sz[Find(u)];
            if (x % cur == 0 && x / cur <= usz) {
              return true;
            }
          }
        }
      }

      idx = nxt;
    }
    return false;
  };

  int lo = 0, hi = q + 1;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << (i <= lo) << "\n";
  }

  return 0;
}