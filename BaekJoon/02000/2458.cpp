// Title : 키 순서
// Link  : https://www.acmicpc.net/problem/2458 
// Time  : 96 ms
// Memory: 3416 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g1(n + 1), g2(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g1[u].push_back(v);
    g2[v].push_back(u);
  }

  vector<bool> vis;

  auto DFS = [&](this auto&& self, int cur, const vector<vector<int>>& g) -> int {
    vis[cur] = true;

    int res = 1;
    for (auto nxt : g[cur]) {
      if (vis[nxt]) continue;
      res += self(nxt, g);
    }
    return res;
  };

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    vis.assign(n + 1, false);
    int x = DFS(i, g1) + DFS(i, g2);
    cnt += (x == n + 1);
  }
  cout << cnt;

  return 0;
}