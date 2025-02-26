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
