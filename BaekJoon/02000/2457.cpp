// Title : 공주님의 정원
// Link  : https://www.acmicpc.net/problem/2457
// Time  : 28 ms
// Memory: 2812 KB

#include <bits/stdc++.h>

using namespace std;

int memo[1232];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr;
  arr.reserve(n);
  for (int i = 0; i < n; i++) {
    int sm, sd, dm, dd;
    cin >> sm >> sd >> dm >> dd;
    int s = sm * 100 + sd, d = dm * 100 + dd;
    if (s >= 1201 || d <= 300) continue;
    arr.push_back({s, d});
  }
  sort(arr.begin(), arr.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  });

  int last = 1201;
  for (auto [s, d] : arr) {
    if (s < last) {
      for (int i = s; i < last; i++) memo[i] = d;
      last = s;
    }
  }

  int cur = 301, ans = 0;
  while (cur < 1201) {
    if (memo[cur] <= cur) {
      ans = 0;
      break;
    }

    cur = memo[cur];
    ++ans;
  }
  cout << ans;

  return 0;
}
