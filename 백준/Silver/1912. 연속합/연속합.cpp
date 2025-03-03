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
