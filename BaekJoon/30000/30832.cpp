// Title : 트리 재구성하기
// Link  : https://www.acmicpc.net/problem/30832 
// Time  : 0 ms
// Memory: 2228 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> edges(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<tuple<int, int, int>> ans;
  [&](this auto&& self, int cur, int par) -> void {
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      if (par) ans.push_back({nxt, cur, 1});
      self(nxt, cur);
    }
  }(1, 0);

  edges.assign(n + 1, vector<int>());
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  [&](this auto&& self, int cur, int par) -> void {
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
      if (par) ans.push_back({nxt, 1, cur});
    }
  }(1, 0);

  cout << ans.size() << "\n";
  for (auto [a, b, c] : ans) cout << a << " " << b << " " << c << "\n";

  return 0;
}
