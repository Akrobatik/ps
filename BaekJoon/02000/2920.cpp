// Title : 음계
// Link  : https://www.acmicpc.net/problem/2920
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nums[8];
  for (int i = 0; i < 8; i++) cin >> nums[i];

  int asc = 1, dsc = 1;
  for (int i = 1; i < 8; i++) {
    if (nums[i - 1] < nums[i]) ++asc;
    if (nums[i - 1] > nums[i]) ++dsc;
  }

  cout << (asc == 8 ? "ascending" : dsc == 8 ? "descending" : "mixed");

  return 0;
}
