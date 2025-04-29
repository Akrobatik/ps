// Title : 색종이 올려 놓기
// Link  : https://www.acmicpc.net/problem/2643 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [y, x] : arr) {
    cin >> y >> x;
    if (y > x) swap(y, x);
  }
  sort(arr.begin(), arr.end());

  int memo[100] = {};
  for (int i = 0; i < n; i++) {
    memo[i] = 1;
    auto [iy, ix] = arr[i];
    for (int j = 0; j < i; j++) {
      auto [jy, jx] = arr[j];
      if (jy <= iy && jx <= ix) memo[i] = max<int>(memo[i], memo[j] + 1);
    }
  }
  cout << *max_element(memo, memo + n);

  return 0;
}
