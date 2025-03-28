#include <bits/stdc++.h>

using namespace std;

int memo[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n((int*)memo, 1001 * 1001, INT_MAX);

  int n, a, b, c, d, e, f;
  cin >> n >> a >> b >> c >> d >> e >> f;

  vector<tuple<int, int, int, int>> acts(n);
  for (auto& [l, ld, h, m] : acts) {
    cin >> l >> h >> m;
    ld = (int)floor((double)(l * (100 - e)) / 100.0);
  }

  memo[0][c] = a;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j <= c; j++) {
      int cur = memo[i][j];
      if (cur == INT_MAX) continue;
      memo[i + 1][j] = min<int>(memo[i + 1][j], cur + f);
      for (auto [l, ld, h, m] : acts) {
        if (j - m < 0 || i + h > b) continue;
        int delta = j > d ? l : ld;
        memo[i + h][j - m] = min<int>(memo[i + h][j - m], max<int>(cur - delta, 0));
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i <= c; i++) {
    ans = min<int>(ans, memo[b][i]);
  }
  cout << ans;

  return 0;
}
