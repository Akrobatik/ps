// Title : 가장 보통의 트리
// Link  : https://www.acmicpc.net/problem/35062 
// Time  : 52 ms
// Memory: 9696 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> sz(n + 1);
  [&](this auto&& self, int cur, int par) -> int {
    int res = 1;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      res += self(nxt, cur);
    }
    return sz[cur] = res;
  }(1, 0);

  vector<int> arr(n + 1);
  vector<pair<int, int>> rng(n + 1);
  [&](this auto&& self, int cur, int par, int l, int r) -> void {
    int dir = (par && arr[par] < l ? 1 : 0);
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      int x = sz[nxt];
      if (dir == 0) {
        rng[nxt] = {l, l + x - 1};
        l += x;
      } else {
        rng[nxt] = {r - x + 1, r};
        r -= x;
      }
      dir ^= 1;
    }
    arr[cur] = l;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      auto [ll, rr] = rng[nxt];
      self(nxt, cur, ll, rr);
    }
  }(1, 0, 1, n);

  for (int i = 1; i <= n; i++) cout << arr[i] << " ";

  return 0;
}