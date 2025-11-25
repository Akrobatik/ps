// Title : Fair Photography
// Link  : https://www.acmicpc.net/problem/10033 
// Time  : 24 ms
// Memory: 4348 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) {
    char c;
    cin >> a >> c;
    b = (c == 'W' ? -1 : 1);
  }
  sort(arr.begin(), arr.end());

  int maxx = 0, cur = 0;
  vector<pair<int, int>> memo[2];
  for (int i = 0; i < n; i++) {
    auto [a, b] = arr[i];
    auto& m1 = memo[i & 1];
    auto& m2 = memo[~i & 1];

    if (m1.empty() || m1.back().first < cur) m1.push_back({cur, a});
    cur += b;

    auto it = lower_bound(m2.begin(), m2.end(), cur, [&](const pair<int, int>& lhs, int rhs) {
      return lhs.first < rhs;
    });

    if (it != m2.end()) maxx = max<int>(maxx, a - it->second);
  }
  cout << maxx;

  return 0;
}