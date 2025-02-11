#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string t, p;
  getline(cin, t, '\n');
  getline(cin, p, '\n');

  int nt = t.size();
  int np = p.size();
  int idx = 0;
  vector<int> table(np, 0);
  for (int i = 1; i < np; i++) {
    while (idx && p[i] != p[idx]) idx = table[idx - 1];
    if (p[i] == p[idx]) table[i] = ++idx;
  }

  vector<int> ans;
  idx = 0;
  for (int i = 0; i < nt; i++) {
    while (idx && t[i] != p[idx]) idx = table[idx - 1];
    if (t[i] == p[idx]) {
      if (++idx == np) {
        ans.push_back(i - np + 2);
        idx = table[idx - 1];
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto v : ans) cout << v << " ";

  return 0;
}
