// Title : 교환 분배법칙
// Link  : https://www.acmicpc.net/problem/31000 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int x = (n << 1) + 1;
  int64_t ans = 0;
  for (int i = -n; i <= n; i++) {
    if (i == 0) {
      ans += x * x;
    } else {
      ans += x - abs(i - 1);
    }
  }
  cout << ans;

  return 0;
}
