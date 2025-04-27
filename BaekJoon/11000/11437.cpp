// Title : LCA
// Link  : https://www.acmicpc.net/problem/11437 
// Time  : 24 ms
// Memory: 8812 KB

#include <bits/stdc++.h>

using namespace std;

int memo[50001];
bool visited[50001];
vector<int> edges[50001];
vector<pair<int, int>> queries[50001];
vector<int> ans;

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

void Traverse(int cur, int par) {
  visited[cur] = true;
  memo[cur] = cur;
  for (auto [x, i] : queries[cur]) {
    if (visited[x]) ans[i] = Find(x);
  }

  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Traverse(nxt, cur);
    memo[nxt] = cur;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (--n) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int m;
  cin >> m;
  ans.resize(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    queries[a].push_back({b, i});
    queries[b].push_back({a, i});
  }

  Traverse(1, 0);
  for (auto e : ans) cout << e << "\n";

  return 0;
}