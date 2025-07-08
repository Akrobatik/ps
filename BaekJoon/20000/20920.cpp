// Title : 영단어 암기는 괴로워
// Link  : https://www.acmicpc.net/problem/20920 
// Time  : 64 ms
// Memory: 13668 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<string, int> hm;

  int n, m;
  cin >> n >> m;
  while (n--) {
    string s;
    cin >> s;
    if (s.size() < m) continue;
    ++hm[s];
  }

  vector<pair<int, string>> arr;
  arr.reserve(hm.size());
  for (auto& [s, cnt] : hm) {
    arr.push_back({cnt, s});
  }

  sort(arr.begin(), arr.end(), [&](const pair<int, string>& lhs, const pair<int, string>& rhs) {
    auto& [lc, ls] = lhs;
    auto& [rc, rs] = rhs;
    return lc > rc || (lc == rc && (ls.size() > rs.size() || (ls.size() == rs.size() && ls.compare(rs) < 0)));
  });

  for (auto& [cnt, s] : arr) cout << s << "\n";

  return 0;
}