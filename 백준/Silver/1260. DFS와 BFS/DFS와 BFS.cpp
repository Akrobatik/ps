#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1001];

void DFS(int cur) {
  bool visited[1001] = {};
  stack<int> st;
  st.push(cur);
  while (!st.empty()) {
    cur = st.top();
    st.pop();
    if (visited[cur]) continue;
    visited[cur] = true;
    cout << cur << " ";
    for (int to : ranges::views::reverse(edges[cur])) {
      if (visited[to]) continue;
      st.push(to);
    }
  }
  cout << "\n";
}

void BFS(int cur) {
  bool visited[1001] = {};
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
  cout << "\n";
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
  BFS(v);

  return 0;
}
