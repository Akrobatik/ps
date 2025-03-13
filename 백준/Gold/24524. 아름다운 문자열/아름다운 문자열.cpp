#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  int memo[256] = {};
  int nt = t.size();
  for (int i = 0; i < nt; i++) {
    memo[t[i]] = i + 1;
  }

  int ans = 0;
  vector<vector<int>> tables;
  for (char c : s) {
    int id = memo[c];
    if (!id) continue;

    if (id == 1) {
      tables.emplace_back(1, 1);
      if (id == nt) ++ans;
      continue;
    }

    auto it = lower_bound(tables.begin(), tables.end(), id - 1, [](const vector<int>& table, int x) {
      return table.back() > x;
    });

    if (it != tables.end() && it->back() == id - 1) {
      it->push_back(id);
      if (id == nt) ++ans;
    }
  }
  cout << ans;

  return 0;
}
