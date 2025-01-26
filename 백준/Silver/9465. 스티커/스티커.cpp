#include <bits/stdc++.h>

using namespace std;

int memo[100001][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    memset(memo, 0, sizeof(memo));
    cin >> n;
    for (int j = 0; j < 2; j++) {
      for (int k = 1; k <= n; k++) cin >> memo[k][j];
    }

    for (int j = 1; j <= n; j++) {
      memo[j][0] += max<int>(memo[j - 1][1], memo[j - 1][2]);
      memo[j][1] += max<int>(memo[j - 1][0], memo[j - 1][2]);
      memo[j][2] += max<int>(memo[j - 1][0], memo[j - 1][1]);
    }

    cout << *max_element(memo[n], memo[n] + 3) << "\n";
  }

  return 0;
}
