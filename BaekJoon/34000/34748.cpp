// Title : K Network Stations
// Link  : https://www.acmicpc.net/problem/34748 
// Time  : 44 ms
// Memory: 10948 KB

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
    [&](this auto&& self, int cur, int par) -> int {
      int res = 1;
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        int val = self(nxt, cur);
        all += (int64_t)val * (n - val) * w;
        res += val;
      }
      return res;
    }(1, 0);

    cout << all;
  } else {
    int64_t maxx = 0, mu, mv, cu, cv;
    [&](this auto&& self, int cur, int par) -> int {
      int res = 1;
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        int val = self(nxt, cur);

        int64_t lrv = (int64_t)val * (n - val) * w;
        if (maxx < lrv) maxx = lrv, mu = nxt, mv = cur, cu = val, cv = n - val;
        res += val;
      }
      return res;
    }(1, 0);

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