// Title : Hipster Jazz
// Link  : https://www.acmicpc.net/problem/35252 
// Time  : 4 ms
// Memory: 2420 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  vector<int> color(n + 1), cnt(n + 1);

  auto Check = [&](int x) {
    return ((g[x].size() + 1) >> 1) <= cnt[x];
  };

  for (int i = 1; i <= n; i++) {
    if (!Check(i)) q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (Check(cur)) continue;

    color[cur] ^= 1, cnt[cur] = g[cur].size() - cnt[cur];
    for (auto nxt : g[cur]) {
      cnt[nxt] += (color[cur] == color[nxt] ? -1 : 1);
      if (!Check(nxt)) q.push(nxt);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (color[i] ? 'S' : 'P');
  }

  return 0;
}