// Title : [A] Artistic Graph Coloring Task
// Link  : https://www.acmicpc.net/problem/34133 
// Time  : 88 ms
// Memory: 13832 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n + 1);
  vector<int> deg(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    ++deg[v];
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  int maxx = 0;
  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : edges[cur]) {
        if (--deg[nxt] == 0) {
          q.push(nxt);
        }
      }
    }
    maxx = i;
  }
  cout << maxx;

  return 0;
}
