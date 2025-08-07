// Title : Tree
// Link  : https://www.acmicpc.net/problem/11429 
// Time  : 28 ms
// Memory: 5564 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e4;

vector<pair<int, int>> edges[kMax + 1];
pair<int, int> memo[kMax + 1];

void DFS1(int cur, int par) {
  auto& [m1, m2] = memo[cur];
  for (auto [nxt, dist] : edges[cur]) {
    if (nxt == par) continue;
    DFS1(nxt, cur);
    int maxx = memo[nxt].first + dist;
    if (maxx > m1) {
      m2 = m1, m1 = maxx;
    } else if (maxx > m2) {
      m2 = maxx;
    }
  }
}

void DFS2(int cur, int par) {
  auto [cm1, cm2] = memo[cur];
  for (auto [nxt, dist] : edges[cur]) {
    if (nxt == par) continue;
    auto& [nm1, nm2] = memo[nxt];
    int maxx = (nm1 + dist != cm1 ? cm1 : cm2) + dist;
    if (maxx > nm1) {
      nm2 = nm1, nm1 = maxx;
    } else if (maxx > nm2) {
      nm2 = maxx;
    }
    DFS2(nxt, cur);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  DFS1(1, 0);
  DFS2(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << memo[i].first << "\n";
  }

  return 0;
}
