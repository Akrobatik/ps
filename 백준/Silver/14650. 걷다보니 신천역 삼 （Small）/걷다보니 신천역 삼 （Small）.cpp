#include <bits/stdc++.h>

using namespace std;

int memo[10][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  int ans = 2;
  for (int i = 2; i < n; i++) {
    ans *= 3;
  }
  cout << ans;

  return 0;
}
