// Title : 이번 시험 다들 다양한 방식으로 망쳤나 봐
// Link  : https://www.acmicpc.net/problem/34731 
// Time  : 100 ms
// Memory: 22632 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  vector<int> vis(n + 1);
  vector<int> memo(n + 1);

  int ord = 0;
  vector<int> stk;
  auto DFS = [&](this auto&& self, int u) -> int {
    int low = vis[u] = ++ord;
    stk.push_back(u);

    for (auto v : g[u]) {
      if (memo[v]) continue;
      low = min<int>(low, vis[v] ? vis[v] : self(v));
    }

    if (vis[u] == low) {  // Root
      int child;
      do {
        child = stk.back();
        stk.pop_back();
        memo[child] = low;
      } while (u != child);
    }
    return vis[u] = low;
  };

  for (int i = 1; i <= n; i++) {
    if (memo[i]) continue;
    DFS(i);
  }

  vector<vector<int>> ng(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto nxt : g[i]) {
      int u = memo[i], v = memo[nxt];
      ng[u].push_back(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    sort(ng[i].begin(), ng[i].end());
    ng[i].erase(unique(ng[i].begin(), ng[i].end()), ng[i].end());
  }

  for (int i = 1; i <= n; i++) {
    stk.push_back(memo[i]);
  }
  sort(stk.begin(), stk.end());
  stk.erase(unique(stk.begin(), stk.end()), stk.end());
  int ans = stk.size();

  queue<int> q;
  vis.assign(n + 1, 0);
  q.push(memo[x]);
  vis[memo[x]] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    --ans;
    for (auto nxt : ng[cur]) {
      if (vis[nxt]) continue;
      vis[nxt] = 1;
      q.push(nxt);
    }
  }
  cout << ans;

  return 0;
}