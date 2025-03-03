#include <bits/stdc++.h>

using namespace std;

int memo[100001];
vector<int> edges[100001];

void Traverse(int cur, int depth) {
  memo[cur] = depth;
  sort(edges[cur].begin(), edges[cur].end());
  for (auto nxt : edges[cur]) {
    if (memo[nxt] != -1) continue;
    Traverse(nxt, depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, -1, sizeof(memo));

  int n, m, s;
  cin >> n >> m >> s;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(s, 0);
  for (int i = 1; i <= n; i++) {
    cout << memo[i] << "\n";
  }

  return 0;
}
