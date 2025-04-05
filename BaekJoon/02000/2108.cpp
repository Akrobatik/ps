// Title : 통계학
// Link  : https://www.acmicpc.net/problem/2108
// Time  : 48 ms
// Memory: 5960 KB

#include <bits/stdc++.h>

using namespace std;

int nums[500000];
int _memo[8001];
int mosts[500000];

inline int Round(int n, int d) {
  auto dv = div(n, d);
  if (dv.rem & 0x80000000) --dv.quot, dv.rem += d;
  return dv.quot + (dv.rem >= (d >> 1) + (d & 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int sum = 0;
  int most = 0;
  int minn = INT_MAX;
  int maxx = INT_MIN;

  int n;
  cin >> n;
  auto memo = _memo + 4000;
  auto mptr = mosts;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
    if (memo[most] < ++memo[nums[i]]) {
      most = nums[i];
      mptr = mosts;
      *mptr++ = nums[i];
    } else if (memo[most] == memo[nums[i]]) {
      *mptr++ = nums[i];
    }
    if (minn > nums[i]) minn = nums[i];
    if (maxx < nums[i]) maxx = nums[i];
  }

  int mid = n >> 1;
  nth_element(nums, nums + mid, nums + n);

  if (mosts + 1 != mptr) {
    nth_element(mosts, mosts + 1, mptr);
    most = mosts[1];
  }

  cout << Round(sum, n) << "\n"
       << nums[mid] << "\n"
       << most << "\n"
       << maxx - minn;

  return 0;
}
