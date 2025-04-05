// Title : 거의 최단 경로
// Link  : https://www.acmicpc.net/problem/5719
// Time  : 36 ms
// Memory: 2280 KB

#include <bits/stdc++.h>

using namespace std;

void Traverse(int start, vector<int>& memo, const vector<vector<pair<int, int>>>& edges, vector<vector<int>>& paths) {
  fill(memo.begin(), memo.end(), INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, start});
  memo[start] = 0;
  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();

    if (memo[cur] < cost) continue;

    for (auto [v, p] : edges[cur]) {
      if (p == 0 || memo[v] < cost + p) continue;
      if (memo[v] == cost + p) {
        paths[v].push_back(cur);
      } else {
        memo[v] = cost + p;
        paths[v].clear();
        paths[v].push_back(cur);
        pq.push({cost + p, v});
      }
    }
  }
}

void Remove(int dest, vector<vector<pair<int, int>>>& edges, const vector<vector<int>>& paths, vector<bool>& visited) {
  if (visited[dest]) return;
  visited[dest] = true;
  for (auto u : paths[dest]) {
    for (auto& [v, p] : edges[u]) {
      if (v != dest) continue;
      p = 0;
      Remove(u, edges, paths, visited);
    }
  }
}

bool Solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0 && m == 0) return false;

  int s, d;
  cin >> s >> d;

  vector<int> memo(n);
  vector<bool> visited(n, false);
  vector<vector<pair<int, int>>> edges(n, vector<pair<int, int>>());
  vector<vector<int>> paths(n, vector<int>());

  while (m--) {
    int u, v, p;
    cin >> u >> v >> p;
    edges[u].push_back({v, p});
  }

  Traverse(s, memo, edges, paths);
  Remove(d, edges, paths, visited);
  Traverse(s, memo, edges, paths);
  cout << (memo[d] != INT_MAX ? memo[d] : -1) << endl;

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (Solve());

  return 0;
}
