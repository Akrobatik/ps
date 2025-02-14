#include <bits/stdc++.h>

using namespace std;

int nums[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto e = nums + n;
  while (n--) cin >> nums[n];
  sort(nums, e);
  cin >> n;
  while (n--) {
    int v;
    cin >> v;
    auto it = lower_bound(nums, e, v);
    cout << (char)('0' + (it != e && *it == v)) << '\n';
  }

  return 0;
}
