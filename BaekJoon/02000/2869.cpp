// Title : 달팽이는 올라가고 싶다
// Link  : https://www.acmicpc.net/problem/2869
// Time  : 0 ms
// Memory: 2020 KB

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
