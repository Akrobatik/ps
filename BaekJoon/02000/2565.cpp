// Title : 전깃줄
// Link  : https://www.acmicpc.net/problem/2565 
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

int memo[501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) cin >> l >> r;
  sort(arr.begin(), arr.end());

  for (auto [l, r] : arr) {
    memo[r] = max<int>(memo[r], memo[r - 1] + 1);
    for (int i = r + 1; i <= 500; i++) {
      memo[i] = max<int>(memo[i], memo[r]);
    }
  }
  cout << n - memo[500];

  return 0;
}
