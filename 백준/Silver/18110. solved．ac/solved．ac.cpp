#include <bits/stdc++.h>

using namespace std;

int memo[31];

inline int Round(int n, int d) {
  auto dv = div(n, d);
  return dv.quot + (dv.rem >= (d >> 1) + (d & 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }

  int t = Round(n * 3, 20);
  int nn = n - (t << 1);

  while (n--) {
    int v;
    cin >> v;
    ++memo[v];
  }

  int sum = 0;
  for (int i = 1; i <= 30; i++) sum += memo[i] * i;

  int rem = t;
  while (rem) {
    for (int i = 1; rem && i <= 30; i++) {
      int v = min<>(rem, memo[i]);
      sum -= v * i;
      rem -= v;
    }
  }

  rem = t;
  while (rem) {
    for (int i = 30; rem && i >= 1; i--) {
      int v = min<>(rem, memo[i]);
      sum -= v * i;
      rem -= v;
    }
  }

  cout << Round(sum, nn);

  return 0;
}
