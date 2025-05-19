// Title : 불꽃놀이의 아름다움 2
// Link  : https://www.acmicpc.net/problem/33915 
// Time  : 136 ms
// Memory: 17120 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];
int memo[200001], dist[200001];

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

bool Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return false;
  memo[b] = a;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  iota(memo, memo + n + 1, 0);
  int cu = 0, cv = 0;
  vector<pair<int, int>> arr(n);
  for (auto& [u, v] : arr) {
    cin >> u >> v;
    if (!Union(u, v)) {
      if (cu == 0 && cv == 0) cu = u, cv = v;
    }
  }

  for (auto [u, v] : arr) {
    if (cu == u && cv == v) continue;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  queue<int> q;
  dist[cu] = 1;
  q.push(cu);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : edges[cur]) {
      if (dist[nxt]) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }

  cout << (2 + (dist[cv] & 1));

  return 0;
}