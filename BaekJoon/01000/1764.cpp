// Title : 듣보잡
// Link  : https://www.acmicpc.net/problem/1764
// Time  : 40 ms
// Memory: 7572 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  map<string, bool> st;
  int n, m;
  cin >> n >> m;

  while (n--) {
    cin >> s;
    st.insert({s, false});
  }

  int cnt = 0;
  while (m--) {
    cin >> s;
    if (auto it = st.find(s); it != st.end()) {
      ++cnt;
      it->second = true;
    }
  }

  cout << cnt << "\n";
  for (auto& [s2, ok] : st) {
    if (ok) cout << s2 << "\n";
  }

  return 0;
}
