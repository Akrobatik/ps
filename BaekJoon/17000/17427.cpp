// Title : 약수의 합 2
// Link  : https://www.acmicpc.net/problem/17427
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t ans = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans += (n / i) * i;
  }
  cout << ans;

  return 0;
}
