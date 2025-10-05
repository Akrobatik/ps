// Title : 즐거운 회의
// Link  : https://www.acmicpc.net/problem/31997 
// Time  : 156 ms
// Memory: 15524 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  vector<int> st(n + 1), en(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> st[i] >> en[i];
  }

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  sort(ids.begin(), ids.end(), [&](int lhs, int rhs) {
    return st[lhs] < st[rhs];
  });

  vector<bool> used(n + 1);
  vector<int> arr(t + 1);
  for (auto u : ids) {
    used[u] = true;
    for (auto v : g[u]) {
      if (!used[v]) continue;
      int s = st[u], e = min<int>(en[u], en[v]);
      if (s < e) ++arr[s], --arr[e];
    }
  }

  for (int i = 1; i <= t; i++) {
    arr[i] += arr[i - 1];
  }

  for (int i = 0; i < t; i++) {
    cout << arr[i] << "\n";
  }

  return 0;
}