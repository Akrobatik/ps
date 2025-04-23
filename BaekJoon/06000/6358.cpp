// Title : Four Quarters
// Link  : https://www.acmicpc.net/problem/6358 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

long double _memo[2][121];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << "Round   A wins    B wins    Tie\n";

  auto memo = _memo[0], mnxt = _memo[1];
  memo[60] = 100;
  for (int i = 1; i <= 20; i++) {
    for (int j = 3; j <= 117; j++) {
      long double x = memo[j];
      mnxt[j - 3] += x / 16.0l;
      mnxt[j - 1] += x * 2 / 16.0l;
      mnxt[j] += x * 6 / 16.0l;
      mnxt[j + 1] += x * 4 / 16.0l;
      mnxt[j + 2] += x * 2 / 16.0l;
      mnxt[j + 3] += x / 16.0l;
    }
    swap(memo, mnxt);
    memset(mnxt, 0, 121 * sizeof(long double));

    long double l = 0, r = 0;
    for (int j = 0; j < 60; j++) l += memo[j];
    for (int j = 61; j <= 120; j++) r += memo[j];

    cout << setw(5) << setfill(' ') << i << setprecision(4) << fixed << setw(10) << r << "%" << setw(9) << l << "%" << setw(9) << memo[60] << (i != 20 ? "%\n" : "%");
  }

  return 0;
}
