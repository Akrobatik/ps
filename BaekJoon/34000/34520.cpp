// Title : 트리 오델로
// Link  : https://www.acmicpc.net/problem/34520 
// Time  : 4 ms
// Memory: 5792 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<int> dist(n);
  [&](this auto&& self, int cur, int par, int d) -> void {
    dist[cur - 1] = d;
    for (auto [nxt, w] : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur, d + w);
    }
  }(1, 0, 0);

  sort(dist.begin(), dist.end());

  vector<pair<int, int>> arr;
  int idx = 0;
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && dist[idx] == dist[nxt]) ++nxt;

    int cnt = nxt - idx;
    arr.push_back({dist[idx], cnt});

    idx = nxt;
  }

  int na = arr.size();
  vector<bitset<5001>> memo(na + 1);
  memo[0][0] = true;
  for (int i = 0; i < na; i++) {
    int x = arr[i].second;
    memo[i + 1] = memo[i] | (memo[i] << x);
  }

  if (!memo[na][m]) {
    cout << "-1";
    return 0;
  }

  vector<bool> color(na);
  int rem = m;
  for (int i = na - 1; i >= 0; i--) {
    int cnt = arr[i].second;
    if (rem >= cnt && memo[i][rem - cnt]) {
      color[i] = true;
      rem -= cnt;
    }
  }

  vector<int> ans;
  for (int i = 0; i < na; i++) {
    bool lb = color[i];
    bool rb = (i + 1 < na ? color[i + 1] : false);
    if (lb != rb) ans.push_back(arr[i].first);
  }

  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";

  return 0;
}