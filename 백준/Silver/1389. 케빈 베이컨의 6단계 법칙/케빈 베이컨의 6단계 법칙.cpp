#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  fill_n((int*)memo, 101 * 101, INT_MAX >> 2);
  for (int i = 1; i <= n; i++) memo[i][i] = 0;

  while (m--) {
    int u, v;
    cin >> u >> v;
    memo[u][v] = 1;
    memo[v][u] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        memo[j][k] = min<int>(memo[j][k], memo[j][i] + memo[i][k]);
      }
    }
  }

  int minn = INT_MAX;
  int min_idx;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) sum += memo[i][j];
    if (minn > sum) minn = sum, min_idx = i;
  }
  cout << min_idx;

  return 0;
}
