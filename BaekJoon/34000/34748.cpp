// Title : K Network Stations
// Link  : https://www.acmicpc.net/problem/34748 
// Time  : 68 ms
// Memory: 16308 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int64_t> cnt(n + 1), wsum(n + 1), vsum(n + 1);
  [&](this auto&& self, int cur, int par) -> void {
    cnt[cur] = 1;
    for (auto [nxt, w] : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
      cnt[cur] += cnt[nxt];
      wsum[cur] += wsum[nxt] + cnt[nxt] * w;
      vsum[cur] += vsum[nxt] + cnt[nxt] * (n - cnt[nxt]) * w;
    }
  }(1, 0);

  if (k == 1) {
    cout << vsum[1];
  } else {
    int64_t minn = INT64_MAX;

    [&](this auto&& self, int cur, int par, int64_t v1, int64_t v2) -> void {
      for (auto [nxt, w] : g[cur]) {
        if (nxt == par) continue;
        int64_t nv1 = v1 + cnt[nxt] * w, nv2 = v2 + (n - cnt[nxt]) * w;
        self(nxt, cur, nv1, nv2);

        int64_t av = vsum[nxt] - wsum[nxt] * (n - cnt[nxt]);
        int64_t bv = vsum[1] - vsum[nxt] - cnt[nxt] * (wsum[1] - wsum[nxt] + nv2 - nv1);
        minn = min<int64_t>(minn, max<int64_t>(av, bv));
      }
    }(1, 0, 0, 0);

    cout << minn;
  }

  return 0;
}