// Title : i18n
// Link  : https://www.acmicpc.net/problem/35115 
// Time  : 4 ms
// Memory: 6152 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  vector<vector<int8_t>> vis(s1.size() + 1, vector<int8_t>(s2.size() + 1));

  bool ok = [&](this auto&& self, string_view sv1, string_view sv2) -> bool {
    if (sv1.empty() && sv2.empty()) return true;
    if (sv1.empty() || sv2.empty()) return false;
    if (sv1.size() < sv2.size()) return false;
    if (vis[sv1.size()][sv2.size()]) return false;
    vis[sv1.size()][sv2.size()] = 1;

    if (sv1[0] == sv2[0] && self(sv1.substr(1), sv2.substr(1))) return true;

    int n1 = sv1.size(), n2 = sv2.size(), x = 0;
    for (int i = 0; i < n2 && '0' <= sv2[i] && sv2[i] <= '9'; i++) {
      x = x * 10 + sv2[i] - '0';
      if (x == 0 || x > n1) break;
      if (self(sv1.substr(x), sv2.substr(i + 1))) return true;
    }
    return false;
  }(s1, s2);

  cout << (ok ? "Yes" : "No");

  return 0;
}