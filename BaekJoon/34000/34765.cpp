// Title : 배열 점수 최대화
// Link  : https://www.acmicpc.net/problem/34765 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  int64_t ans = INT64_MIN;
  for (int64_t i = 0; i < n; i++) {
    int64_t len = n - i;
    int64_t val = k + i - (len >> 1);
    ans = max<int64_t>(ans, len * val);
  }
  for (int64_t i = 0; i < n; i++) {
    int64_t len = n - i;
    int64_t val = k - (len >> 1);
    ans = max<int64_t>(ans, len * val);
  }
  cout << ans;

  return 0;
}