#include <bits/stdc++.h>

using namespace std;

int memo[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    memo[i] = memo[i - 1] + 1;
    auto d2 = div(i, 2), d3 = div(i, 3);
    if (!d2.rem && memo[i] > memo[d2.quot] + 1) memo[i] = memo[d2.quot] + 1;
    if (!d3.rem && memo[i] > memo[d3.quot] + 1) memo[i] = memo[d3.quot] + 1;
  }
  cout << memo[n];

  return 0;
}
