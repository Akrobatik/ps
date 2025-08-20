// Title : 1, 2, 3 더하기 4
// Link  : https://www.acmicpc.net/problem/15989 
// Time  : 0 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e5;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int64_t> memo(kMax + 1, 1);
  for (int i = 2; i <= kMax; i++) memo[i] += memo[i - 2];
  for (int i = 3; i <= kMax; i++) memo[i] += memo[i - 3];

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << memo[n] << "\n";
  }

  return 0;
}