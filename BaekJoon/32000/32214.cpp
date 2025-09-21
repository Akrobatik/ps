// Title : 코코아와 마법사의 돌
// Link  : https://www.acmicpc.net/problem/32214 
// Time  : 0 ms
// Memory: 2224 KB

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

  vector<int> color[5];

  [&](this auto&& self, int cur, int par, int d) -> void {
    color[d % 5].push_back(cur);
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur, d + 1);
    }
  }(1, 0, 0);

  int idx = 0, m = n / 5;
  while (color[idx].size() > m + 1) ++idx;

  auto& arr = color[idx];
  int na = arr.size();
  cout << max<int>(na - 1, 0) << "\n";
  for (int i = 1; i < na; i++) {
    cout << arr[0] << " " << arr[i] << "\n";
  }

  return 0;
}