// Title : 수 정렬하기 2
// Link  : https://www.acmicpc.net/problem/2751
// Time  : 248 ms
// Memory: 5928 KB

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
