// Title : 평균
// Link  : https://www.acmicpc.net/problem/1546
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int nums[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int sum = 0;
  int maxx = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sum += nums[i];
    if (maxx < nums[i]) maxx = nums[i];
  }

  cout.precision(2);
  cout << fixed << (double)sum / (double)maxx * 100.0 / (double)n;

  return 0;
}
