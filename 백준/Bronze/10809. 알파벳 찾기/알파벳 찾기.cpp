#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int memo[26];
  fill(memo, memo + 26, INT_MAX);

  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (memo[s[i] - 'a'] > i) memo[s[i] - 'a'] = i;
  }

  for (auto e : memo) cout << (e != INT_MAX ? e : -1) << " ";

  return 0;
}
