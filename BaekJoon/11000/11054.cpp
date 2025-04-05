// Title : 가장 긴 바이토닉 부분 수열
// Link  : https://www.acmicpc.net/problem/11054
// Time  : 0 ms
// Memory: 2028 KB

#include <bits/stdc++.h>

using namespace std;

uint16_t nums[1000];
uint16_t memo[2][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int16_t> vec;
  vec.reserve(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    auto it = upper_bound(vec.begin(), vec.end(), nums[i], less_equal<>());
    if (it != vec.end()) {
      *it = nums[i];
      memo[1][i] = memo[1][i - 1];
    } else {
      vec.push_back(nums[i]);
      memo[1][i] = nums[i];
    }
    memo[0][i] = vec.size();
  }

  vec.clear();
  int max_value = 0;
  for (int i = n - 1; i >= 0; i--) {
    auto it = upper_bound(vec.begin(), vec.end(), nums[i], less_equal<>());
    if (it != vec.end()) {
      *it = nums[i];
    } else {
      vec.push_back(nums[i]);
      max_value = nums[i];
    }
    if (i > 0) memo[0][i - 1] += vec.size() - (memo[1][i - 1] == max_value ? 1 : 0);
  }

  cout << max<int>(*max_element(memo[0], memo[0] + n), vec.size()) << endl;

  return 0;
}
