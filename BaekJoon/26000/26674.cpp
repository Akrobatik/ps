// Title : Mieszanie kolorów
// Link  : https://www.acmicpc.net/problem/26674 
// Time  : 328 ms
// Memory: 13740 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> memo(n + 1);
  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    --l, --k;
    ++memo[l][k], --memo[r][k];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) memo[i][j] += memo[i - 1][j];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (memo[i][2] == 0 && memo[i][0] > 0 && memo[i][1] > 0);
  }
  cout << ans;

  return 0;
}
