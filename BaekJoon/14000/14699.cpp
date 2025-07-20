// Title : 관악산 등산
// Link  : https://www.acmicpc.net/problem/14699 
// Time  : 20 ms
// Memory: 3072 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[5001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<int> deg(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (arr[u] < arr[v]) swap(u, v);
    edges[u].push_back(v);
    ++deg[v];
  }

  queue<int> q;
  vector<int> dist(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : edges[u]) {
      dist[v] = max<int>(dist[v], dist[u] + 1);
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << dist[i] << "\n";

  return 0;
}
