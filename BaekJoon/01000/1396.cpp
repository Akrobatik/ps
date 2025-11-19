// Title : 크루스칼의 공
// Link  : https://www.acmicpc.net/problem/1396 
// Time  : 280 ms
// Memory: 43264 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<tup> adj(m);
  for (auto& [w, u, v] : adj) cin >> u >> v >> w;
  sort(adj.begin(), adj.end());

  int q;
  cin >> q;
  vector<pair<int, int>> qr(q);
  for (auto& [x, y] : qr) cin >> x >> y;

  vector<int> memo, cnt;

  auto Init = [&]() {
    memo.resize(n + 1);
    iota(memo.begin(), memo.end(), 0);

    cnt.assign(n + 1, 1);
  };

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    memo[b] = a;
    cnt[a] += cnt[b];
  };

  int maxx = get<0>(adj.back());
  vector<vector<int>> cands(maxx + 1);
  vector<int> lo(q, 0), hi(q, maxx + 1), sz(q);
  for (;;) {
    bool none = true;
    for (int i = 0; i < q; i++) {
      if (lo[i] + 1 < hi[i]) {
        int mid = (lo[i] + hi[i]) >> 1;
        cands[mid].push_back(i);
        none = false;
      }
    }
    if (none) break;

    Init();

    int idx = 0;
    for (int i = 1; i <= maxx; i++) {
      auto& cand = cands[i];
      if (cand.empty()) continue;

      while (idx < m && get<0>(adj[idx]) <= i) {
        auto [w, u, v] = adj[idx++];
        Union(u, v);
      }

      for (auto qi : cand) {
        auto [x, y] = qr[qi];
        int px = Find(x), py = Find(y);
        if (px == py) {
          hi[qi] = i;
          sz[qi] = cnt[px];
        } else {
          lo[qi] = i;
        }
      }
      cand.clear();
    }
  }

  for (int i = 0; i < q; i++) {
    int w = hi[i];
    if (w <= maxx) {
      cout << w << " " << sz[i] << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}