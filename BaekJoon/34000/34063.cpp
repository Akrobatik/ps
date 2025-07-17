// Title : OPS 분석
// Link  : https://www.acmicpc.net/problem/34063 
// Time  : 152 ms
// Memory: 18476 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 20150116;

int memo[81][81][321], mnxt[81][81][321];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, y;
  long double _y;
  cin >> x >> _y;
  y = (int64_t)round(_y * 1000.0L);

  memo[0][0][0] = 1;
  for (int i = 0; i < x; i++) {
    memset(mnxt, 0, sizeof(mnxt));
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i; k++) {
        int limit = i * 4;
        for (int l = 0; l <= limit; l++) {
          if (memo[j][k][l] == 0) continue;
          for (int m = 1; m <= 4; m++) {
            if ((mnxt[j][k][l + m] += memo[j][k][l]) >= kMod) mnxt[j][k][l + m] -= kMod;
          }
          if ((mnxt[j + 1][k][l] += memo[j][k][l]) >= kMod) mnxt[j + 1][k][l] -= kMod;
          if ((mnxt[j][k + 1][l] += memo[j][k][l]) >= kMod) mnxt[j][k + 1][l] -= kMod;
        }
      }
    }
    memcpy(memo, mnxt, sizeof(memo));
  }

  int ans = 0;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j <= x; j++) {
      int limit = x * 4;
      for (int k = 0; k <= limit; k++) {
        if (memo[i][j][k] == 0) continue;
        int64_t lv = ((x - i) * (x - j) + x * k) * 1000;
        int64_t rv = y * x * (x - i);
        if (lv >= rv) {
          if ((ans += memo[i][j][k]) >= kMod) ans -= kMod;
        }
      }
    }
  }
  cout << ans;

  return 0;
}
