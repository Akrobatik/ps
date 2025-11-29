// Title : $N$중 슬릿 실험
// Link  : https://www.acmicpc.net/problem/34854 
// Time  : 0 ms
// Memory: 2036 KB

#include <bits/stdc++.h>

using namespace std;

constexpr long double kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h;
  cin >> w >> h;

  vector<array<int64_t, 2>> arr(h + 2);
  for (int i = 1; i <= h; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }

  vector<array<long double, 2>> memo(h + 2, {kInf, kInf});
  memo[0] = {0, 0};
  for (int i = 1; i <= h + 1; i++) {
    for (int e = 0; e < 2; e++) {
      int64_t ev = arr[i][e];
      for (int j = 0; j < i; j++) {
        for (int s = 0; s < 2; s++) {
          int64_t sv = arr[j][s];
          bool ok = true;
          for (int k = j + 1; ok && k < i; k++) {
            auto [ml, mr] = arr[k];
            ok = ((mr - sv) * (i - j) >= (ev - sv) * (k - j) && (ev - sv) * (k - j) >= (ml - sv) * (i - j));
          }
          if (ok) {
            long double x = (long double)abs(ev - sv), y = (long double)(i - j);
            memo[i][e] = min<long double>(memo[i][e], memo[j][s] + hypot(x, y));
          }
        }
      }
    }
  }

  cout << setprecision(6) << fixed << memo[h + 1][0];

  return 0;
}