// Title : 분해합
// Link  : https://www.acmicpc.net/problem/2231
// Time  : 0 ms
// Memory: 2116 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int minn = n - (log10(n) + 1) * 9;
  for (int i = minn; i < n; i++) {
    int v = i;
    int sum = v;
    while (v) {
      auto dv = div(v, 10);
      sum += dv.rem;
      v = dv.quot;
    }
    if (sum == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
