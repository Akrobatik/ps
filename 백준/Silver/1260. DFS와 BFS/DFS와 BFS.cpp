#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1001];
bool visited[1001];

void DFS(int cur) {
  cout << cur << " ";
  visited[cur] = true;
  for (int to : edges[cur]) {
    if (visited[to]) continue;
    DFS(to);
  }
}

void BFS(int cur) {
  queue<int> q;
  visited[cur] = true;
  q.push(cur);
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    cout << cur << " ";
    for (int to : edges[cur]) {
      if (visited[to]) continue;
      visited[to] = true;
      q.push(to);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, v;
  cin >> n >> m >> v;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
  }

  DFS(v);
  cout << "\n";
  memset(visited, 0, sizeof(visited));
  BFS(v);

  return 0;
}
