#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  vector<int> memo(n, 0);

  int rem = 0, cnt;
  for (int i = 1; i < n; i++) {
    auto& x = memo[i];
    if (rem) x = min<int>(rem--, memo[++cnt]);
    while (i + x < n && s[i + x] == s[x]) ++x;
    if (rem < x - 1) rem = x - 1, cnt = 0;
  }
  memo[0] = n;

  auto sorted = memo;
  sort(sorted.begin(), sorted.end());
  vector<pair<int, int>> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (memo[i] + i == n) {
      int cnt = sorted.end() - lower_bound(sorted.begin(), sorted.end(), memo[i]);
      ans.push_back({n - i, cnt});
    }
  }

  cout << ans.size() << "\n";
  for (auto [i, cnt] : ans) {
    cout << i << " " << cnt << "\n";
  }

  return 0;
}
