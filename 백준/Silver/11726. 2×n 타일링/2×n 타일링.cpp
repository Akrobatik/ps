#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[1001];
  memo[1] = 1, memo[2] = 2;

  int n;
  cin >> n;
  for (int i = 3; i <= n; i++) {
    memo[i] = memo[i - 1] + memo[i - 2];
    if (memo[i] >= 10007) memo[i] -= 10007;
  }
  cout << memo[n];

  return 0;
}
