#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> edges(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u < v) swap(u, v);
    edges[u].push_back(v);
  }

  for (int i = 2; i <= n; i++) {
    if (edges[i].empty()) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";

  return 0;
}
