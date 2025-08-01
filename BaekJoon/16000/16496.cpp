// Title : 큰 수 만들기
// Link  : https://www.acmicpc.net/problem/16496 
// Time  : 0 ms
// Memory: 2184 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> qs(n);
  for (auto& s : qs) cin >> s;

  sort(qs.begin(), qs.end(), [&](const string& lhs, const string& rhs) {
    string lv = lhs + rhs;
    string rv = rhs + lhs;
    return lv.compare(rv) > 0;
  });

  string ans;
  for (auto& s : qs) {
    ans.insert(ans.end(), s.begin(), s.end());
  }

  int idx = 0;
  while (idx + 1 < ans.size() && ans[idx] == '0') ++idx;

  string_view sv(ans);
  cout << sv.substr(idx);

  return 0;
}
