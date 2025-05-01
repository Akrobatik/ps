// Title : 겹치는 건 싫어
// Link  : https://www.acmicpc.net/problem/20922 
// Time  : 16 ms
// Memory: 3072 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int memo[100001] = {};

  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int ans = 0, l = 0, r = 0;
  for (;;) {
    while (r < n && memo[arr[r]] < k) ++memo[arr[r++]];
    ans = max<int>(ans, r - l);
    if (r == n) break;
    while (l < r && arr[l] != arr[r]) --memo[arr[l++]];
    --memo[arr[l++]];
  }
  cout << ans;

  return 0;
}
