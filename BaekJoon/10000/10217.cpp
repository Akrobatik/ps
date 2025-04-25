// Title : KCM Travel
// Link  : https://www.acmicpc.net/problem/10217 
// Time  : 192 ms
// Memory: 6196 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

vector<tup> edges[100];
int memo[10001][100];

void Solve() {
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    edges[u - 1].push_back({v - 1, c, d});
  }

  for (int i = 0; i < n; i++) {
    sort(edges[i].begin(), edges[i].end(), [](const tup& lhs, const tup& rhs) {
      return get<1>(lhs) < get<1>(rhs);
    });
  }

  fill_n((int*)memo, 100 * 10001, INT_MAX);
  memo[0][0] = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (memo[i][j] == INT_MAX) continue;
      for (auto [nxt, cost, dist] : edges[j]) {
        if (i + cost > m) break;
        memo[i + cost][nxt] = min<int>(memo[i + cost][nxt], memo[i][j] + dist);
      }
    }
  }

  int minn = INT_MAX;
  for (int i = 0; i <= m; i++) {
    minn = min<int>(minn, memo[i][n - 1]);
  }
  
  if (minn != INT_MAX) {
    cout << minn << "\n";
  } else {
    cout << "Poor KCM\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
