#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t res = 1;
  for (int i = 2; i <= n; i++) {
    res *= i;
    while (res % 10 == 0) res /= 10;
    res %= 1000000;
  }
  cout << res % 10;

  return 0;
}
