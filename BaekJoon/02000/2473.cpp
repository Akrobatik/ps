// Title : 세 용액
// Link  : https://www.acmicpc.net/problem/2473
// Time  : 24 ms
// Memory: 2060 KB

#include <bits/stdc++.h>

using namespace std;

int64_t nums[5000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);

  int64_t ans[3];
  int64_t minn = INT64_MAX;
  for (int i = 0; i < n - 2; i++) {
    int64_t fixed = nums[i];
    auto b = nums + i + 1;
    auto e = nums + n - 1;
    while (b != e) {
      int64_t sum = *b + *e + fixed;
      int64_t sum_abs = abs(sum);
      if (minn > sum_abs) {
        minn = sum_abs;
        ans[0] = fixed;
        ans[1] = *b;
        ans[2] = *e;
      }

      if (sum > 0) {
        --e;
      } else {
        ++b;
      }
    }
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2];

  return 0;
}
