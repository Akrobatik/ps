#include <bits/stdc++.h>

using namespace std;

int n;
int cost[1000][3];
int memo[3][1000][3];

void Traverse(int sp, int m[1000][3]) {
  for (int i = 0; i < 3; i++) {
    if (i == sp) {
      m[1][i] = INT_MAX;
    } else {
      m[1][i] = cost[1][i] + cost[0][sp];
    }
  }
  if (n == 2) return;
  for (int i = 0; i < 3; i++) {
    if (i == sp) {
      m[2][i] = cost[2][i] + min<int>(m[1][0], min<int>(m[1][1], m[1][2]));
    } else {
      m[2][i] = cost[2][i] + m[1][3 - sp - i];
    }
  }
  for (int i = 3; i < n; i++) {
    m[i][0] = cost[i][0] + min<int>(m[i - 1][1], m[i - 1][2]);
    m[i][1] = cost[i][1] + min<int>(m[i - 1][0], m[i - 1][2]);
    m[i][2] = cost[i][2] + min<int>(m[i - 1][0], m[i - 1][1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

  Traverse(0, memo[0]);
  Traverse(1, memo[1]);
  Traverse(2, memo[2]);

  static constexpr pair<int, int> cands[] = {
      {0, 1},
      {0, 2},
      {1, 0},
      {1, 2},
      {2, 0},
      {2, 1},
  };

  int ans = INT_MAX;
  for (auto [b, e] : cands)
    if (memo[b][n - 1][e] != INT_MAX)
      ans = min<int>(ans, memo[b][n - 1][e]);
  cout << ans << "\n";

  return 0;
}
