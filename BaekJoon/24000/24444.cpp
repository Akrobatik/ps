// Title : 알고리즘 수업 － 너비 우선 탐색 1
// Link  : https://www.acmicpc.net/problem/24444
// Time  : 84 ms
// Memory: 9552 KB

#include <bits/stdc++.h>

using namespace std;

int memo[100001];
vector<int> edges[100001];

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

  int idx = 0;
  queue<int> q;
  memo[r] = ++idx;
  q.push(r);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    sort(edges[cur].begin(), edges[cur].end());
    for (auto nxt : edges[cur]) {
      if (memo[nxt]) continue;
      memo[nxt] = ++idx;
      q.push(nxt);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << memo[i] << "\n";
  }

  return 0;
}
