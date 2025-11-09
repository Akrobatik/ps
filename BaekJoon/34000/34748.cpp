// Title : K Network Stations
// Link  : https://www.acmicpc.net/problem/34748 
// Time  : 48 ms
// Memory: 14432 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  if (k == 1) {
    int64_t all = 0;
    vector<int64_t> cnt(n + 1), sum(n + 1);

    [&](this auto&& self, int cur, int par) -> void {
      cnt[cur] = 1;
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur);
        cnt[cur] += cnt[nxt];
        sum[cur] += sum[nxt] + cnt[nxt] * w;
        all += cnt[nxt] * (n - cnt[nxt]) * w;
      }
    }(1, 0);

    cout << all;
  } else {
    vector<int64_t> cnt(n + 1), sum(n + 1);
    [&](this auto&& self, int cur, int par) -> void {
      cnt[cur] = 1;
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur);
        cnt[cur] += cnt[nxt];
        sum[cur] += sum[nxt] + cnt[nxt] * w;
      }
    }(1, 0);

    int64_t maxx = 0, mu, mv;
    [&](this auto&& self, int cur, int par) -> void {
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur);
        int64_t lv = sum[nxt] + cnt[nxt] * w;
        int64_t rv = sum[cur] - lv;
        int64_t lrv = lv * rv;
        if (maxx < lrv) maxx = lrv, mu = nxt, mv = cur;
      }
    }(1, 0);

    int64_t cu = cnt[mu], cv = n - cu;

    auto Calc = [&](this auto&& self, int u, int p, int s) -> int {
      int64_t all = 0;
      [&](this auto&& self, int cur, int par) -> int {
        int res = 1;
        for (auto [nxt, w] : g[cur]) {
          if (nxt == par) continue;
          int val = self(nxt, cur);
          all += (int64_t)val * (s - val) * w;
          res += val;
        }
        return res;
      }(u, p);
      return all;
    };

    cout << max<int64_t>(Calc(mu, mv, cu), Calc(mv, mu, cv));
  }

  return 0;
}