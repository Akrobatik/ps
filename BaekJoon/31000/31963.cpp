// Title : 두 배
// Link  : https://www.acmicpc.net/problem/31963 
// Time  : 28 ms
// Memory: 4960 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int8_t> lrr(1000001);
  for (int i = 2; i <= 1000000; i++) lrr[i] = lrr[i >> 1] + 1;

  int n;
  cin >> n;
  vector<int> arr(n), brr(n);
  for (auto& e : arr) cin >> e;

  int64_t ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] <= arr[i]) {
      int l = lrr[arr[i] / arr[i - 1]];
      brr[i] = max<int>(brr[i - 1] - l, 0);
    } else {
      int l = lrr[arr[i - 1] / arr[i]];
      brr[i] = brr[i - 1] + l + (arr[i - 1] != (arr[i] << l));
    }
    ans += brr[i];
  }
  cout << ans;

  return 0;
}
