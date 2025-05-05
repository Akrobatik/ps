// Title : 합이 0
// Link  : https://www.acmicpc.net/problem/3151 
// Time  : 1108 ms
// Memory: 2184 KB

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
  arr.push_back(1234567);

  int64_t ans = 0;
  for (int i = 0; i < n && arr[i] <= 0; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = arr[i] + arr[j];
      if (x + arr[j] > 0) break;
      auto it = lower_bound(arr.begin() + j + 1, arr.end(), -x);
      if (x + *it != 0) continue;
      ans += upper_bound(arr.begin() + j + 1, arr.end(), -x) - it;
    }
  }
  cout << ans;

  return 0;
}
