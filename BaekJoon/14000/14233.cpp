// Title : 악덕 사장
// Link  : https://www.acmicpc.net/problem/14233 
// Time  : 8 ms
// Memory: 2256 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    ans = min<int>(ans, arr[i] / (i + 1));
  }
  cout << ans;

  return 0;
}
