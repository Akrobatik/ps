#include <bits/stdc++.h>

using namespace std;

int _memo[12];
auto memo = _memo + 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memo[0] = 1;
  for (int i = 1; i <= 10; i++) {
    memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << memo[n] << "\n";
  }

  return 0;
}
