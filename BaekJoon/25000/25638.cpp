// Title : 트리와 경로 개수 쿼리
// Link  : https://www.acmicpc.net/problem/25638 
// Time  : 56 ms
// Memory: 10612 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int idx = 0;
  vector<int> in(n + 1), out(n + 1), fwd(n + 1);
  vector<int64_t> memo(n + 1);
  [&](this auto&& self, int cur, int par) -> array<int64_t, 2> {
    array<int64_t, 2> res{};
    in[cur] = ++idx;
    fwd[idx] = fwd[idx - 1] + arr[cur];
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      auto cnt = self(nxt, cur);
      memo[cur] += res[0] * cnt[1] + res[1] * cnt[0];
      res[0] += cnt[0], res[1] += cnt[1];
    }
    out[cur] = idx;
    ++res[arr[cur]];
    return res;
  }(1, 0);

  for (int i = 1; i <= n; i++) {
    int64_t x1 = fwd[out[i]] - fwd[in[i]], x2 = out[i] - in[i] - x1;
    int64_t y1 = fwd[in[i] - 1] + fwd[n] - fwd[out[i]], y2 = n - (out[i] - in[i] + 1) - y1;
    memo[i] += x1 * y2 + x2 * y1;
  }

  int m;
  cin >> m;
  while (m--) {
    int u;
    cin >> u;
    cout << memo[u] << "\n";
  }

  return 0;
}