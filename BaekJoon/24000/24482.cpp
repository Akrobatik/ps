// Title : 알고리즘 수업 － 깊이 우선 탐색 4
// Link  : https://www.acmicpc.net/problem/24482
// Time  : 80 ms
// Memory: 15616 KB

#include <bits/stdc++.h>

using namespace std;

int idx;
int memo[100001];
vector<int> edges[100001];

void Traverse(int cur, int h) {
  memo[cur] = h;
  sort(edges[cur].begin(), edges[cur].end(), greater<>());
  for (auto nxt : edges[cur]) {
    if (memo[nxt]) continue;
    Traverse(nxt, h + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r;
  cin >> n >> m >> r;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(r, 1);

  for (int i = 1; i <= n; i++) {
    cout << memo[i] - 1 << "\n";
  }

  return 0;
}
