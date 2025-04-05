// Title : 요세푸스 문제 3
// Link  : https://www.acmicpc.net/problem/11025
// Time  : 28 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    ans += k;
    while (ans > i) ans -= i;
  }
  cout << ans;

  return 0;
}
