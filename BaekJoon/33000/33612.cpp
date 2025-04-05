// Title : 피갤컵
// Link  : https://www.acmicpc.net/problem/33612
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  pair<int, int> ans[] = {
      {2024, 8},
      {2025, 3},
      {2025, 10},
      {2026, 5},
      {2026, 12},
  };

  int n;
  cin >> n;
  cout << ans[n - 1].first << " " << ans[n - 1].second;

  return 0;
}
