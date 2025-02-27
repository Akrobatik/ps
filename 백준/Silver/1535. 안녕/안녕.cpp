#include <bits/stdc++.h>

using namespace std;

int memo[101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i].first;
  for (int i = 0; i < n; i++) cin >> vec[i].second;

  for (auto [nd, np] : vec) {
    for (int i = 100 - nd; i >= 0; i--) {
      memo[i + nd] = max<int>(memo[i + nd], memo[i] + np);
    }
  }
  cout << *max_element(memo, memo + 100);

  return 0;
}
