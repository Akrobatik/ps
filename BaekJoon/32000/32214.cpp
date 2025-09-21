// Title : 코코아와 마법사의 돌
// Link  : https://www.acmicpc.net/problem/32214 
// Time  : 0 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  vector<bool> visited;

  auto Push = [&](int x) {
    if (visited[x]) return;
    visited[x] = true;
    q.push(x);
  };

  vector<int> cands;
  vector<bool> used(n + 1);
  int m = n / 5;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;

    cands.clear();
    visited.assign(n + 1, false);

    Push(i);
    for (int j = 0; !q.empty(); j++) {
      int nq = q.size();
      while (nq--) {
        int cur = q.front();
        q.pop();

        if (j % 5 == 0) cands.push_back(cur);

        for (auto nxt : g[cur]) {
          Push(nxt);
        }
      }
    }

    if (cands.size() <= m + 1) break;

    for (auto e : cands) used[e] = true;
  }

  int na = cands.size();
  cout << max<int>(na - 1, 0) << "\n";
  for (int i = 1; i < na; i++) {
    cout << cands[0] << " " << cands[i] << "\n";
  }

  return 0;
}