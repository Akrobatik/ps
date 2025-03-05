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
