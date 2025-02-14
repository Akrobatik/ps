#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, v;
  cin >> a >> b >> v;

  int ans = 1;
  v -= a;
  if (v > 0) {
    auto dv = div(v, a - b);
    ans += dv.quot + (dv.rem != 0);
  }
  cout << ans;

  return 0;
}
