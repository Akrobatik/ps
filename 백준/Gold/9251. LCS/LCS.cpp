#include <bits/stdc++.h>

using namespace std;

char s1[1001], s2[1001];
int16_t memo[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s1 >> s2;
  int n1 = strlen(s1);
  int n2 = strlen(s2);
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (s1[i - 1] == s2[j - 1])
        memo[i][j] = memo[i - 1][j - 1] + 1;
      else
        memo[i][j] = max<int16_t>(memo[i - 1][j], memo[i][j - 1]);
    }
  }

  int16_t ans = 0;
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= n2; j++) {
      if (ans < memo[i][j]) ans = memo[i][j];
    }
  }
  cout << ans << endl;

  return 0;
}
