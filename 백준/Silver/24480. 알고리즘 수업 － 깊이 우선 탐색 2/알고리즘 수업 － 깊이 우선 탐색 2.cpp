#include <bits/stdc++.h>

using namespace std;

int memo[100001];
vector<int> edges[100001];
int idx;

void Traverse(int cur) {
  memo[cur] = ++idx;
  sort(edges[cur].begin(), edges[cur].end(), greater<>());
  for (auto nxt :edges[cur]) {
    if (memo[nxt]) continue;
    Traverse(nxt);
  }
}

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
  Traverse(s);

  for (int i = 1; i <= n; i++) {
    cout << memo[i] << "\n";
  }

  return 0;
}
