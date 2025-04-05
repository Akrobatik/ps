// Title : GCD（n， k） ＝ 1
// Link  : https://www.acmicpc.net/problem/11689
// Time  : 4 ms
// Memory: 3008 KB

#include <bits/stdc++.h>

using namespace std;

bool memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;
  int64_t nn = sqrt(n);
  int64_t ans = n;
  for (int64_t i = 2; i <= nn; i++) {
    if (memo[i]) continue;
    for (int j = (i << 1); j <= nn; j += i) memo[j] = true;
    auto dv = div(n, i);
    if (dv.rem) continue;
    ans -= ans / i;
    n = dv.quot;
    while (n % i == 0) n /= i;
  }
  if (n != 1) ans -= ans / n;

  cout << ans;

  return 0;
}
