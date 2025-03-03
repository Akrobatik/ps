#include <bits/stdc++.h>

using namespace std;

int memo[100001];
vector<int> edges[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s;
  cin >> n >> m >> s;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int idx = 0;
  queue<int> q;
  memo[s] = ++idx;
  q.push(s);
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    sort(edges[cur].begin(), edges[cur].end(), greater<>());
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
