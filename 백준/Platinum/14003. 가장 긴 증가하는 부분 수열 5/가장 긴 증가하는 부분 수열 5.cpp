#include <bits/stdc++.h>

using namespace std;

int64_t nums[1000000];
int64_t memo[1000000];
int idx[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto me = memo;
  auto ie = idx;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    auto it = lower_bound(memo, me, nums[i]);
    if (it != me) {
      *ie++ = it - memo;
      *it = nums[i];
    } else {
      *ie++ = me - memo;
      *me++ = nums[i];
    }
  }

  int nm = me - memo;
  me = memo;
  cout << nm-- << "\n";
  for (int i = n - 1; i >= 0; i--) {
    if (idx[i] == nm) {
      *me++ = nums[i];
      --nm;
    }
  }

  for (auto p = me - 1; p >= memo; --p) cout << *p << " ";

  return 0;
}
