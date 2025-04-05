// Title : 랜선 자르기
// Link  : https://www.acmicpc.net/problem/1654
// Time  : 4 ms
// Memory: 2100 KB

#include <bits/stdc++.h>

using namespace std;

int64_t nums[10000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t k, n;
  cin >> k >> n;
  int64_t e = 0;
  for (int i = 0; i < k; i++) {
    cin >> nums[i];
    if (e < nums[i]) e = nums[i];
  }

  int64_t ans = 0;
  int64_t b = 1;
  while (b <= e) {
    int64_t mid = (b + e) >> 1;
    int64_t sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i] / mid;
    if (sum < n) {
      e = mid - 1;
    } else {
      ans = mid;
      b = mid + 1;
    }
  }

  cout << ans;

  return 0;
}
