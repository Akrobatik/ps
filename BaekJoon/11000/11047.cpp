// Title : 동전 0
// Link  : https://www.acmicpc.net/problem/11047
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> coins(n);
  while (n--) cin >> coins[n];

  int ans = 0;
  for (int coin : coins) {
    auto dv = div(k, coin);
    ans += dv.quot;
    k = dv.rem;
  }
  cout << ans;

  return 0;
}
