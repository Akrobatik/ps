// Title : Hybrid Search
// Link  : https://www.acmicpc.net/problem/35246 
// Time  : 40 ms
// Memory: 11336 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int idx = 0;
  vector<int> in(n + 1), out(n + 1);

  [&](this auto&& self, int cur, int par) -> void {
    in[cur] = ++idx;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      self(nxt, cur);
    }
    out[cur] = idx;
  }(1, 0);

  vector<int8_t> vis(n + 1);
  vector<int> bo(n + 1);
  queue<int> q;

  auto Push = [&](int x) {
    if (vis[x]) return;
    vis[x] = 1;
    q.push(x);
  };

  idx = 0;
  Push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    bo[cur] = ++idx;
    for (auto nxt : g[cur]) {
      Push(nxt);
    }
  }

  int bcnt = bo[m];
  for (int i = 1; i <= n; i++) {
    if (bo[i] >= bcnt) continue;

    if (in[i] <= in[m] && out[m] <= out[i]) {
      bcnt = min<int>(bcnt, bo[i] + in[m] - in[i]);
    }
  }

  vector<int> fwd(n + 1);
  for (int i = 1; i <= n; i++) {
    fwd[in[i]] = (bo[i] <= bo[m]);
  }
  for (int i = 0; i < n; i++) {
    fwd[i + 1] += fwd[i];
  }

  int dcnt = in[m];
  for (int i = 1; i <= n; i++) {
    if (in[i] >= dcnt) continue;

    if (in[i] <= in[m] && out[m] <= out[i]) {
      dcnt = min<int>(dcnt, in[i] + fwd[out[i]] - fwd[in[i]]);
    }
  }

  cout << bcnt << "\n"
       << dcnt;

  return 0;
}