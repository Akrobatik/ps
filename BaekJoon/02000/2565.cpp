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
    memo[r] = max<int>(memo[r], *max_element(memo, memo + r) + 1);
  }
  cout << n - *max_element(memo, memo + 501);

  return 0;
}
