#include <bits/stdc++.h>

using namespace std;

int items[101][2];
int memo[101][100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> items[i][0] >> items[i][1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      int w = items[i][0];
      if (j < w)
        memo[i][j] = memo[i - 1][j];
      else
        memo[i][j] = max<int>(memo[i - 1][j], memo[i - 1][j - w] + items[i][1]);
    }
  }

  cout << memo[n][k] << endl;

  return 0;
}
