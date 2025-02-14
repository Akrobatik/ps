#include <bits/stdc++.h>

using namespace std;

int nums[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];
  sort(nums, nums + n);
  for (int i = 0; i < n; i++) cout << nums[i] << "\n";

  return 0;
}
