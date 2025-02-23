#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pii> table(n);
  while (n--) cin >> table[n].first >> table[n].second;
  sort(table.begin(), table.end(), [](const pii& lhs, const pii& rhs) {
    return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
  });

  int cnt = 0, end = 0;
  for (auto [s, e] : table) {
    if (end <= s) ++cnt, end = e;
  }
  cout << cnt;

  return 0;
}
