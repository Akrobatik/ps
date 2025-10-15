// Title : 1학년
// Link  : https://www.acmicpc.net/problem/5557 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int64_t, 21>> memo(n);
  memo[0][0] = 1;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    for (int j = x; j <= 20; j++) {
      memo[i][j] += memo[i - 1][j - x];
      if (i != 1) memo[i][j - x] += memo[i - 1][j];
    }
  }

  int x;
  cin >> x;
  cout << memo[n - 1][x];

  return 0;
}