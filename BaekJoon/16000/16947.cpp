// Title : 서울 지하철 2호선
// Link  : https://www.acmicpc.net/problem/16947 
// Time  : 0 ms
// Memory: 2348 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  vector<int> deg(n + 1);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    ++deg[u], ++deg[v];
  }

  queue<int> q;
  vector<int8_t> cyc(n + 1, 1);

  for (int i = 1; i <= n; i++) {
    if (deg[i] != 1) continue;
    cyc[i] = 0;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      if (--deg[nxt] == 1) {
        cyc[nxt] = 0;
        q.push(nxt);
      }
    }
  }

  vector<int> dist(n + 1, -1);

  auto Push = [&](int x, int d) {
    if (dist[x] != -1) return;
    dist[x] = d;
    q.push(x);
  };

  for (int i = 1; i <= n; i++) {
    if (cyc[i]) Push(i, 0);
  }

  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : g[cur]) {
        Push(nxt, i);
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << dist[i] << " ";

  return 0;
}