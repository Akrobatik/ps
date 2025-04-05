// Title : 최대 페이지 수
// Link  : https://www.acmicpc.net/problem/16493
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[201];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vec(m);
  for (int i = 0; i < m; i++) cin >> vec[i].first >> vec[i].second;

  for (auto [nd, np] : vec) {
    for (int i = n - nd; i >= 0; i--) {
      memo[i + nd] = max<int>(memo[i + nd], memo[i] + np);
    }
  }
  cout << *max_element(memo, memo + n + 1);

  return 0;
}
