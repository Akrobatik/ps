// Title : 구름다리
// Link  : https://www.acmicpc.net/problem/22967 
// Time  : 0 ms
// Memory: 2156 KB

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

  vector<pair<int, int>> adj;
  if (n <= 4) {
    for (int i = 1; i <= n; i++) {
      bool used[5] = {};
      used[i] = true;
      for (auto e : g[i]) used[e] = true;
      for (int j = 1; j <= n; j++) {
        if (used[j]) continue;
        adj.push_back({i, j});
        g[j].push_back(i);
      }
    }
  } else {
    vector<bool> used(n + 1);
    used[1] = true;
    for (auto e : g[1]) used[e] = true;
    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;
      adj.push_back({1, i});
    }
  }

  cout << adj.size() << "\n"
       << (n <= 4 ? 1 : 2) << "\n";
  for (auto [u, v] : adj) cout << u << " " << v << "\n";

  return 0;
}