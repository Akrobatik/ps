// Title : 자벌레 세기
// Link  : https://www.acmicpc.net/problem/34875 
// Time  : 136 ms
// Memory: 20668 KB

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

  int64_t cnt = 0;
  for (int u = 1; u <= n; u++) {
    int64_t uc = g[u].size();
    if (uc < 3) continue;

    int64_t ux = (uc - 1) * (uc - 2) / 2;
    for (auto v : g[u]) {
      int64_t vc = g[v].size();
      if (vc < 3) continue;

      int64_t vx = (vc - 1) * (vc - 2) / 2;
      cnt += ux * vx;
    }
  }
  cout << cnt / 2;

  return 0;
}