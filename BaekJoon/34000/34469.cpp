// Title : Floor is Lava
// Link  : https://www.acmicpc.net/problem/34469 
// Time  : 1448 ms
// Memory: 43928 KB

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int, int, int>;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<tuple<int, int, int>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    int nu = g[u].size(), nv = g[v].size();
    g[u].push_back({v, nv, w});
    g[v].push_back({u, nu, w});
  }

  vector<vector<int>> nidx(n + 1);
  for (int i = 1; i <= n; i++) {
    nidx[i].resize(g[i].size());
  }

  vector<int> tmp;
  for (int i = 1; i <= n; i++) {
    int sz = g[i].size();
    tmp.resize(sz);
    for (int j = 0; j < sz; j++) {
      tmp[j] = get<2>(g[i][j]);
    }
    sort(tmp.begin(), tmp.end());

    for (auto [v, nv, w] : g[i]) {
      int ord = lower_bound(tmp.begin(), tmp.end(), w) - tmp.begin();
      nidx[v][nv] = ord;
    }
  }

  for (int i = 1; i <= n; i++) {
    int sz = g[i].size();
    for (int j = 0; j < sz; j++) {
      get<1>(g[i][j]) = nidx[i][j];
    }
  }

  vector<vector<int64_t>> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    int sz = g[i].size();
    memo[i].assign(sz, i != 1 ? kInf : 0);
  }

  priority_queue<tup, vector<tup>, greater<tup>> pq;
  pq.push({0, 1, 0, 0, 0});
  while (!pq.empty()) {
    auto [d, cur, ci, cw, prv] = pq.top();
    pq.pop();

    if (memo[cur][ci] != d) continue;
    if (cur == n) break;

    for (auto [nxt, ni, w] : g[cur]) {
      if (nxt == prv) continue;
      int64_t nd = d + abs(cw - w);
      if (memo[nxt][ni] <= nd) continue;
      memo[nxt][ni] = nd;
      pq.push({nd, nxt, ni, w, cur});
    }
  }

  cout << *min_element(memo[n].begin(), memo[n].end());

  return 0;
}