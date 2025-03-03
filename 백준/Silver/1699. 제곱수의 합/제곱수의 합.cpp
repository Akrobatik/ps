#include <bits/stdc++.h>

using namespace std;

int memo[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    memo[i] = i;
    for (int j = 1; j * j <= i; j++) {
      if (memo[i] > memo[i - j * j] + 1) memo[i] = memo[i - j * j] + 1;
    }
  }
  cout << memo[n];

  return 0;
}
