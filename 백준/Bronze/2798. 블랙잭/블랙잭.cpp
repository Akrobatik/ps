#include <bits/stdc++.h>

using namespace std;

int nums[100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);

  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    int fixed = nums[i];
    auto b = nums + i + 1;
    auto e = nums + n - 1;
    while (b != e) {
      int sum = *b + *e + fixed;
      if (sum > m) {
        --e;
      } else {
        if (ans < sum) ans = sum;
        ++b;
      }
    }
  }
  cout << ans;

  return 0;
}
