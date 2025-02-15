#include <bits/stdc++.h>

using namespace std;

int nums[3 * (int)1e5];

inline int Round(int n, int d) {
  auto dv = div(n, d);
  return dv.quot + (dv.rem >= (d >> 1) + (d & 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
  }
  sort(nums, nums + n);
  int trim = Round(n * 3, 20);
  if (n > trim * 2) {
    for (int i = 0; i < trim; i++) sum -= nums[i] + nums[n - i - 1];
    cout << Round(sum, n - trim * 2);
  } else {
    cout << 0;
  }

  return 0;
}
