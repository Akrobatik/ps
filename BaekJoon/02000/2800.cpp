// Title : 괄호 제거
// Link  : https://www.acmicpc.net/problem/2800 
// Time  : 0 ms
// Memory: 2188 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  vector<int> stk;
  vector<pair<int, int>> cands;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stk.push_back(i);
    } else if (s[i] == ')') {
      cands.push_back({stk.back(), i});
      stk.pop_back();
    }
  }

  vector<string> ans;
  string tmp = s, tmp2;
  int nb = cands.size();
  int limit = 1 << nb;
  ans.reserve(limit);
  for (int i = 1; i < limit; i++) {
    bitset<10> bits(i);
    copy(s.begin(), s.end(), tmp.begin());
    for (int b = 0; b < nb; b++) {
      if (!bits.test(b)) continue;
      auto [l, r] = cands[b];
      tmp[l] = tmp[r] = '$';
    }

    tmp2.clear();
    for (auto c : tmp) {
      if (c == '$') continue;
      tmp2.push_back(c);
    }
    ans.push_back(tmp2);
  }

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (auto& s : ans) cout << s << "\n";

  return 0;
}
