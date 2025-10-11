// Title : 돌멩이 제거
// Link  : https://www.acmicpc.net/problem/1867 
// Time  : 0 ms
// Memory: 2220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> g(n + 1);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  int cnt = 0;
  vector<int> cover(n + 1);
  vector<bool> vis;
  for (int i = 1; i <= n; i++) {
    vis.assign(n + 1, false);

    cnt += [&](this auto&& self, int cur) -> int {
      for (auto nxt : g[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        if (!cover[nxt] || self(cover[nxt])) {
          cover[nxt] = cur;
          return 1;
        }
      }
      return 0;
    }(i);
  }
  cout << cnt;

  return 0;
}