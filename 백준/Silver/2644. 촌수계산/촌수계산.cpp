#include <bits/stdc++.h>

using namespace std;

int src, dst;
vector<int> edges[101];

int Traverse(int cur, int par, int len) {
  if (cur == dst) return len;

  int res = -1;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    int v = Traverse(nxt, cur, len + 1);
    if (v != -1) res = v;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> src >> dst >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  cout << Traverse(src, 0, 0);

  return 0;
}
