#include <bits/stdc++.h>

using namespace std;

int items[101];
int memo[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n((int*)memo, 101 * 101, INT_MAX);
  for (int i = 0; i <= 100; i++) memo[i][i] = 0;

  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) cin >> items[i];
  for (int i = 0; i < r; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    memo[a][b] = min<int>(memo[a][b], c);
    memo[b][a] = min<int>(memo[b][a], c);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (memo[j][i] != INT_MAX && memo[i][k] != INT_MAX)
          memo[j][k] = min<int>(memo[j][k], memo[j][i] + memo[i][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (memo[i][j] <= m) cnt += items[j];
    }
    ans = max<int>(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
