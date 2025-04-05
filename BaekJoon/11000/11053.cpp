// Title : 가장 긴 증가하는 부분 수열
// Link  : https://www.acmicpc.net/problem/11053
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  uint16_t cnts[1000];
  uint16_t nums[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];

    int max_cnt = 0;
    int max_id = -1;
    for (int j = 0; j < i; j++) {
      if (max_cnt < cnts[j] && nums[j] < nums[i]) {
        max_cnt = cnts[j];
      }
    }

    cnts[i] = max_cnt + 1;
  }

  cout << *max_element(begin(cnts), begin(cnts) + n) << endl;

  return 0;
}
