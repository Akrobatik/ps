// Title : 트리 게임
// Link  : https://www.acmicpc.net/problem/34769 
// Time  : 128 ms
// Memory: 18244 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> deg(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u], ++deg[v];
  }

  int64_t ans = (n - 1) << 1;

  vector<pair<int, int>> arr;
  vector<int64_t> mul(n + 1), sub(n + 1);
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    arr.clear();
    for (auto u : g[i]) {
      ok &= (deg[u] <= 2);
      if (deg[u] != 2) continue;
      int v = (i != g[u][0] ? g[u][0] : g[u][1]);
      arr.push_back({u, v});
    }

    if (ok && arr.size() == 1) {
      auto [u, v] = arr[0];
      mul[v] += 1;
      sub[v] += deg[u] - 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    int64_t cnt = 0;
    for (auto u : g[i]) {
      cnt += deg[u] - 1;
    }
    ans += mul[i] * cnt - sub[i];
  }

  vector<int8_t> chk;
  for (int i = 1; i <= n; i++) {
    int sz = g[i].size();
    chk.resize(sz);

    for (int j = 0; j < sz; j++) {
      int v = g[i][j];
      chk[j] = (deg[v] >= 2);
    }

    int64_t cnt = accumulate(chk.begin(), chk.end(), 0);
    if (cnt == 1) {
      for (int j = 0; j < sz; j++) {
        if (chk[j] == 0) continue;
        int v = g[i][j];
        ans += deg[v] - 1;
      }
    }
  }
  cout << ans;

  return 0;
}