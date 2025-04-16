// Title : 선 긋기
// Link  : https://www.acmicpc.net/problem/2170 
// Time  : 344 ms
// Memory: 9836 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) cin >> l >> r;
  sort(arr.begin(), arr.end());

  int ans = 0, x = INT_MIN;
  for (auto [l, r] : arr) {
    ans += max<int>(r - max<int>(x, l), 0);
    x = max<int>(x, r);
  }
  cout << ans;

  return 0;
}
