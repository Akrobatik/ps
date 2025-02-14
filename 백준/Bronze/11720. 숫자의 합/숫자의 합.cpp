#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int ans = 0;
  while (n--) {
    char c;
    cin >> c;
    ans += (c - '0');
  }
  cout << ans;

  return 0;
}
