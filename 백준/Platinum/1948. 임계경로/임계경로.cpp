#include <bits/stdc++.h>

using namespace std;

int maxt[10001];
int memo[10001];
vector<pair<int, int>> edges[10001], r_edges[10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    r_edges[v].push_back({u, w});
    ++memo[v];
  }
  int src, dst;
  cin >> src >> dst;

  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto [nxt, w] : edges[cur]) {
      if (maxt[nxt] < maxt[cur] + w) maxt[nxt] = maxt[cur] + w;
      if (--memo[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  int cnt = 0;
  q.push(dst);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto& [prv, w] : r_edges[cur]) {
      if (maxt[cur] == maxt[prv] + w) {
        ++cnt;
        q.push(prv);
        w = 0;
      }
    }
  }

  cout << maxt[dst] << "\n"
       << cnt;

  return 0;
}
