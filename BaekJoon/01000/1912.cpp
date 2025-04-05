// Title : 연속합
// Link  : https://www.acmicpc.net/problem/1912
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, cur, ans;
  cin >> n >> x;
  cur = ans = x;
  while (--n) {
    cin >> x;
    if (cur < 0) {
      cur = x;
    } else {
      cur += x;
    }
    if (ans < cur) ans = cur;
  }
  cout << ans;

  return 0;
}
