// Title : Monotone Subsequence
// Link  : https://www.acmicpc.net/problem/34630 
// Time  : 552 ms
// Memory: 13956 KB

#include <bits/stdc++.h>

using namespace std;

vector<bool> used;
vector<vector<int>> results;
vector<int> ans;

void Solve() {
  int n;
  cin >> n;
  int m = n * n + 1;
  used.assign(m + 1, false);
  results.assign(n, vector<int>());

  int rem = m;
  for (auto& res : results) {
    cout << "? " << rem;
    for (int i = 1; i <= m; i++) {
      if (used[i]) continue;
      cout << " " << i;
    }
    cout << endl;

    int sz;
    cin >> sz;
    res.resize(sz);
    for (auto& e : res) cin >> e, used[e] = true;
    rem -= sz;

    if (sz >= n + 1) {
      cout << "!";
      for (int i = 0; i <= n; i++) cout << " " << res[i];
      cout << endl;
      return;
    }
  }

  int last = m;
  while (used[last]) --last;
  ans.clear();
  ans.push_back(last);
  for (auto& res : views::reverse(results)) {
    auto it = upper_bound(res.rbegin(), res.rend(), last, greater<int>());
    last = *it;
    ans.push_back(last);
  }

  cout << "!";
  for (auto e : views::reverse(ans)) cout << " " << e;
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}