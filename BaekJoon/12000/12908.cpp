// Title : 텔레포트 3
// Link  : https://www.acmicpc.net/problem/12908 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> coords(8);
  for (auto& [y, x] : coords) {
    cin >> y >> x;
  }

  int memo[8][8];
  for (int i = 0; i < 8; i++) {
    auto [iy, ix] = coords[i];
    for (int j = 0; j < 8; j++) {
      auto [jy, jx] = coords[j];
      memo[i][j] = abs(iy - jy) + abs(ix - jx);
    }
  }

  for (int i = 2; i < 8; i += 2) {
    if (memo[i][i + 1] <= 10) continue;
    memo[i][i + 1] = memo[i + 1][i] = 10;
  }

  for (int k = 0; k < 8; k++) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        memo[i][j] = min<int64_t>(memo[i][j], (int64_t)memo[i][k] + memo[k][j]);
      }
    }
  }
  cout << memo[0][1];

  return 0;
}