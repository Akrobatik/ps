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
