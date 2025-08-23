// Title : 테토와 바게트
// Link  : https://www.acmicpc.net/problem/34156 
// Time  : 336 ms
// Memory: 22256 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n), axr;
  for (auto& [s, e] : arr) cin >> s >> e;
  sort(arr.begin(), arr.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [ls, le] = lhs;
    auto [rs, re] = rhs;
    return ls < rs || (ls == rs && le > re);
  });

  int idx = 0;
  while (idx < n) {
    auto [s, e] = arr[idx];
    axr.push_back({s, e});
    while (idx < n && arr[idx].second <= e) ++idx;
  }

  int prv = 0, cnt = 0;
  for (auto [s, e] : axr) {
    if (s < prv && prv < e) continue;
    prv = e - 1;
    ++cnt;
  }

  cout << cnt;

  return 0;
}