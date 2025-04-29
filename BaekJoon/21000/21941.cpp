// Title : 문자열 제거
// Link  : https://www.acmicpc.net/problem/21941 
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int m;
  cin >> s >> m;
  vector<pair<string, int>> arr(m);
  for (auto& [a, x] : arr) cin >> a >> x;
  sort(arr.begin(), arr.end(), [](const pair<string, int>& lhs, const pair<string, int>& rhs) {
    return lhs.first.size() < rhs.first.size();
  });

  string_view sv = s;
  vector<int> memo(s.size() + 1);
  for (int i = 1; i <= s.size(); i++) {
    memo[i] = memo[i - 1] + 1;
    for (auto& [a, x] : arr) {
      if (a.size() > i) break;
      auto sub = sv.substr(i - a.size(), a.size());
      if (sub.compare(a) == 0) memo[i] = max<int>(memo[i], memo[i - a.size()] + x);
    }
  }
  cout << memo[s.size()];

  return 0;
}
