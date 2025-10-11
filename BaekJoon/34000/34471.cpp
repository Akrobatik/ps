// Title : MIT Tour
// Link  : https://www.acmicpc.net/problem/34471 
// Time  : 232 ms
// Memory: 60680 KB

#include <bits/stdc++.h>

using namespace std;

struct LCA {
  void Init(const vector<vector<int>>& g, int rt) {
    int n = g.size();
    ord.resize(n + 1);
    par.resize(n + 1);
    asc.resize(n + 1);
    dep.resize(n + 1);
    in.resize(n + 1);
    head.resize(n + 1);

    int idx = 0;
    auto DFS = [&](auto&& self, int u) -> void {
      int cur = ++idx;
      ord[idx] = u;
      in[u] = cur;
      for (auto v : g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        self(self, v);
        head[in[v]] = u;
        if ((in[u] & -in[u]) < (in[v] & -in[v])) in[u] = in[v];
      }
    };

    par[rt] = asc[rt] = dep[rt] = head[rt] = 0;
    DFS(DFS, rt);

    for (int i = 1; i <= idx; i++) {
      int u = ord[i], p = par[u];
      asc[u] = asc[p] | (in[u] & -in[u]);
    }
  }

  int Query(int u, int v) {
    if (in[u] ^ in[v]) {
      int x = asc[u] & asc[v] & -bit_floor((uint32_t)(in[u] ^ in[v]));
      if (asc[u] ^ x) {
        int k = bit_floor((uint32_t)(asc[u] ^ x));
        u = head[(in[u] & -k) | k];
      }
      if (asc[v] ^ x) {
        int k = bit_floor((uint32_t)(asc[v] ^ x));
        v = head[(in[v] & -k) | k];
      }
    }
    return dep[u] < dep[v] ? u : v;
  }

 private:
  vector<int> ord, par, asc, dep, in, head;
};

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int md = 0, nidx = 0;
  vector<int64_t> dist(n + 1);
  vector<vector<int>> groups(n);
  vector<vector<int>> ng(n + 1);
  vector<int> parent(n + 1);

  [&](this auto&& self, int cur, int par, int d, int64_t s) -> int {
    md = max<int>(md, d);
    int co = ++nidx;
    dist[co] = s;
    groups[d].push_back(co);
    for (auto [nxt, w] : g[cur]) {
      if (nxt == par) continue;
      int no = self(nxt, cur, d + 1, s + w);
      parent[no] = co;
      ng[co].push_back(no);
    }
    return co;
  }(1, 0, 0, 0);

  LCA lca;
  lca.Init(ng, 1);

  vector<int64_t> memo(n + 1, kInf);
  for (auto e : ng[1]) memo[e] = dist[e];

  vector<int> arr, stk;
  vector<pair<int64_t, int>> m1(n + 1), m2(n + 1);
  for (int d = 1; d < md; d++) {
    auto& grp = groups[d];
    int sz = grp.size();
    arr.resize(sz << 1);
    arr[0] = 1;
    for (int i = 1; i < sz; i++) {
      int u = grp[i - 1], v = grp[i];
      arr[i] = lca.Query(u, v);
    }

    copy(grp.begin(), grp.end(), arr.begin() + sz);
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (auto i : arr) ng[i].clear();

    stk.clear();
    for (auto i : arr) {
      while (!stk.empty() && stk.back() != lca.Query(stk.back(), i)) stk.pop_back();
      if (!stk.empty()) {
        int p = stk.back();
        ng[p].push_back(i);
      }
      stk.push_back(i);
    }

    for (auto i : arr) {
      m1[i] = (ng[i].empty() ? make_pair(memo[i], i) : make_pair(kInf, 0));
      m2[i] = {kInf, 0};
    }

    auto Push = [&](int i, pair<int64_t, int> pr) {
      if (m1[i] > pr) {
        m2[i] = m1[i];
        m1[i] = pr;
      } else if (m2[i] > pr) {
        m2[i] = pr;
      }
    };

    [&](this auto&& self, int cur) -> void {
      for (auto nxt : ng[cur]) {
        self(nxt);
        auto pr = m1[nxt];
        pr.first += dist[nxt] - dist[cur];
        Push(cur, pr);
      }
    }(1);

    [&](this auto&& self, int cur) -> void {
      for (auto nxt : ng[cur]) {
        pair<int64_t, int> pr;
        if (nxt != lca.Query(nxt, m1[cur].second)) {
          pr = m1[cur];
        } else {
          pr = m2[cur];
        }
        pr.first += dist[nxt] - dist[cur];
        Push(nxt, pr);
        self(nxt);
      }
    }(1);

    for (auto e : groups[d + 1]) {
      int p = parent[e];
      int64_t w = dist[e] - dist[p];
      if (m1[p].second != p) {
        memo[e] = m1[p].first + w;
      } else {
        memo[e] = m2[p].first + w;
      }
    }
  }

  int64_t ans = kInf;
  for (auto e : groups[md]) {
    ans = min<int64_t>(ans, memo[e]);
  }
  cout << ans;

  return 0;
}