// Title : 인덕이와 산책
// Link  : https://www.acmicpc.net/problem/33933 
// Time  : 32 ms
// Memory: 2312 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> cycle(t);
  for (auto& e : cycle) cin >> e, --e;

  vector<vector<bool>> visited(t, vector<bool>(n));

  queue<int> q;

  auto Push = [&](int x, int r) {
    if (visited[r][x]) return;
    visited[r][x] = true;
    q.push(x);
  };

  Push(0, 0);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      if (cur + 1 == n) {
        cout << i;
        return 0;
      }

      int cr = i % t, nr = (cr + 1) % t;
      if (cycle[cr] == cur) {
        Push(cycle[nr], nr);
        continue;
      }

      Push(cur, nr);
      for (auto nxt : edges[cur]) {
        Push(nxt, nr);
      }
    }
  }
  cout << "-1";

  return 0;
}
