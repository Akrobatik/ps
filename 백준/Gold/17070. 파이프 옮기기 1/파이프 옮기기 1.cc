#include <bits/stdc++.h>

using namespace std;

int memo[17][17][3];
bool blocks[17][17];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  memo[1][2][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      bool block = c != '0';
      blocks[i][j] = block;
      if (!block && j > 2) {
        memo[i][j][0] = memo[i][j - 1][0] + memo[i][j - 1][1];
        memo[i][j][2] = memo[i - 1][j][1] + memo[i - 1][j][2];
        if (!blocks[i - 1][j] && !blocks[i][j - 1])
          memo[i][j][1] = memo[i - 1][j - 1][0] + memo[i - 1][j - 1][1] + memo[i - 1][j - 1][2];
      }
    }
  }

  cout << accumulate(memo[n][n], memo[n][n] + 3, 0) << endl;

  return 0;
}
