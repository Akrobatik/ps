// Title : 불 뿌리기
// Link  : https://www.acmicpc.net/problem/34718 
// Time  : 1704 ms
// Memory: 108756 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dep(n + 1);
  vector<array<int, 18>> par(n + 1);

  [&](this auto&& self, int u, int p, int d) -> void {
    dep[u] = d;
    par[u][0] = p;
    for (int i = 1; i < 20 && par[u][i - 1]; i++) {
      par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto v : g[u]) {
      if (v == p) continue;
      self(v, u, d + 1);
    }
  }(1, 0, 0);

  auto LCA = [&](int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    int dt = dep[v] - dep[u];
    while (dt) {
      int lsb = dt & (-dt);
      dt ^= lsb;
      v = par[v][countr_zero((uint32_t)lsb)];
    }
    if (u == v) return u;

    int i = bit_width((uint32_t)dep[u]);
    while (i--) {
      int pu = par[u][i], pv = par[v][i];
      if (pu != pv) u = pu, v = pv;
    }
    return par[u][0];
  };

  auto Find = [&](int u, int v, int l, int x) {
    int lud = dep[u] - dep[l];
    int lvd = dep[v] - dep[l];
    if (x > lud) {
      x = lud + lvd - x;
      u = v;
    }
    while (x) {
      int lsb = x & (-x);
      x ^= lsb;
      u = par[u][countr_zero((uint32_t)lsb)];
    }
    return u;
  };

  vector<tup> arr;
  while (m--) {
    int t, u, v, ru, rv;
    cin >> t >> u >> v >> ru >> rv;
    if (ru > rv) swap(u, v), swap(ru, rv);
    int lca = LCA(u, v);
    int dr = rv - ru;
    int dt = dep[u] + dep[v] - (dep[lca] << 1);
    if (ru + rv < dt) continue;

    if (dr < dt) {
      int rem = dt - dr;
      int half = rem >> 1;
      int mu = half, mv = half + dr;
      int uu = Find(u, v, lca, mu), vv = Find(v, u, lca, mv);
      arr.push_back({t, uu, ru - mu - (rem & 1)});
      arr.push_back({t, vv, ru - mu - (rem & 1)});
    } else {
      arr.push_back({t, u, ru});
    }
  }

  vector<map<int, int, greater<int>>> memo(n + 1);

  auto Push = [&](int i, int d, int r) {
    auto& mp = memo[i];
    auto it = mp.lower_bound(d);
    if (it != mp.end() && it->second >= r) return false;

    while (it != mp.begin() && prev(it)->second <= r) it = mp.erase(prev(it));
    mp[d] = r;
    return true;
  };

  auto Check = [&](int i, int d, int r) {
    auto& mp = memo[i];
    auto it = mp.find(d);
    if (it == mp.end()) return false;
    return it->second == r;
  };

  auto Cmp = [&](const tup& lhs, const tup& rhs) {
    auto [lt, lr, lx] = lhs;
    auto [rt, rr, rx] = rhs;
    return lt > rt || (lt == rt && lr < rr);
  };

  vector<int> dist(n + 1, INT_MAX);
  priority_queue<tup, vector<tup>, decltype(Cmp)> pq(Cmp);
  for (auto [t, x, r] : arr) {
    if (Push(x, t, r)) pq.push({t, r, x});
  }

  while (!pq.empty()) {
    auto [d, r, cur] = pq.top();
    pq.pop();

    if (!Check(cur, d, r)) continue;
    dist[cur] = min<int>(dist[cur], d);

    int nd = (r > 0 ? d : d + k), nr = (r > 0 ? r - 1 : 0);
    for (auto nxt : g[cur]) {
      if (Push(nxt, nd, nr)) pq.push({nd, nr, nxt});
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (dist[i] != INT_MAX ? dist[i] : -1) << "\n";
  }

  return 0;
}