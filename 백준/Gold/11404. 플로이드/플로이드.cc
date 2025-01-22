#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  fill_n((int*)memo, 101 * 101, INT_MAX);
  for (int i = 1; i <= n; i++) memo[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    memo[a][b] = min<int>(memo[a][b], c);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (memo[j][i] != INT_MAX && memo[i][k] != INT_MAX)
          memo[j][k] = min<int>(memo[j][k], memo[j][i] + memo[i][k]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (memo[i][j] == INT_MAX ? 0 : memo[i][j]) << " ";
    }
    cout << "\n";
  }

  return 0;
}
