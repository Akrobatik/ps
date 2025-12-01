// Title : 진흥이의 쌀 배달
// Link  : https://www.acmicpc.net/problem/34876 
// Time  : 0 ms
// Memory: 2232 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<int64_t> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 0; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int64_t ans = 0;
  [&](this auto&& self, int cur, int par) -> int64_t {
    int64_t res = arr[cur];
    for (auto [nxt, w] : g[cur]) {
      if (nxt == par) continue;
      int64_t val = self(nxt, cur);
      res += val;

      int64_t cnt = (val + k - 1) / k;
      ans += cnt * w;
    }
    return res;
  }(0, -1);

  cout << ans * 2;

  return 0;
}