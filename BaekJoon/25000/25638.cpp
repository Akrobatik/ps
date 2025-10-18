// Title : 트리와 경로 개수 쿼리
// Link  : https://www.acmicpc.net/problem/25638 
// Time  : 56 ms
// Memory: 9136 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n;
  cin >> n;

  uint32_t s = 0;
  vector<uint8_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    uint32_t x;
    cin >> x;
    arr[i] = x;
    s += x;
  }

  vector<vector<uint32_t>> g(n + 1);
  for (int i = 1; i < n; i++) {
    uint32_t u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  uint32_t all[2] = {n - s, s};

  vector<uint64_t> memo(n + 1);
  [&](this auto&& self, int cur, int par) -> array<uint32_t, 2> {
    array<uint32_t, 2> res{};
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      auto cnt = self(nxt, cur);
      memo[cur] += res[0] * cnt[1] + res[1] * cnt[0];
      res[0] += cnt[0], res[1] += cnt[1];
    }

    if (arr[cur]) {
      memo[cur] += res[0] * (all[1] - res[1] - 1) + res[1] * (all[0] - res[0]);
      ++res[1];
    } else {
      memo[cur] += res[0] * (all[1] - res[1]) + res[1] * (all[0] - res[0] - 1);
      ++res[0];
    }
    return res;
  }(1, 0);

  uint32_t m;
  cin >> m;
  while (m--) {
    uint32_t u;
    cin >> u;
    cout << memo[u] << "\n";
  }

  return 0;
}