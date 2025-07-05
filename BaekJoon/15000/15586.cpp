// Title : MooTube (Gold)
// Link  : https://www.acmicpc.net/problem/15586 
// Time  : 68 ms
// Memory: 5548 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> memo(n + 1), sz(n + 1, 1);
  iota(memo.begin(), memo.end(), 0);

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
    sz[a] += sz[b];
  };

  vector<tup>
      edges(n - 1);
  for (auto& [w, u, v] : edges) cin >> u >> v >> w;
  sort(edges.begin(), edges.end());

  vector<int> ans(q);
  vector<tup> queries(q);
  for (int i = 0; i < q; i++) {
    auto& [k, v, qi] = queries[i];
    cin >> k >> v;
    qi = i;
  }
  sort(queries.begin(), queries.end(), greater<tup>());

  for (auto [qk, qv, qi] : queries) {
    while (!edges.empty() && get<0>(edges.back()) >= qk) {
      auto [w, u, v] = edges.back();
      edges.pop_back();

      Union(u, v);
    }

    ans[qi] = sz[Find(qv)] - 1;
  }

  for (auto e : ans) cout << e << "\n";

  return 0;
}
