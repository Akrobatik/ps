// Title : 트리의 독립집합
// Link  : https://www.acmicpc.net/problem/2213 
// Time  : 4 ms
// Memory: 2884 KB

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

  vector<array<int, 2>> memo(n + 1);

  [&](this auto&& self, int cur, int par) -> void {
    memo[cur][0] = arr[cur];
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
      auto [incl, excl] = memo[nxt];
      memo[cur][0] += excl;
      memo[cur][1] += max<int>(incl, excl);
    }
  }(1, 0);

  vector<int> onoff(n + 1);
  [&](this auto&& self, int cur, int par) -> void {
    if (!onoff[par] && memo[cur][0] >= memo[cur][1]) onoff[cur] = 1;

    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
    }
  }(1, 0);

  cout << max<int>(memo[1][0], memo[1][1]) << "\n";
  for (int i = 1; i <= n; i++) {
    if (onoff[i]) cout << i << " ";
  }

  return 0;
}