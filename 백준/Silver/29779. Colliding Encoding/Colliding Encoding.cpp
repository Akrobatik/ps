#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int table[26];

  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    for (int i = 0; i < 26; i++) cin >> table[i];

    int n;
    cin >> n;
    set<int64_t> st;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int64_t key = 0;
      for (char c : s) key <<= 4, key |= (table[c - 'A'] + 1);
      st.insert(key);
    }

    cout << "Case #" << ti << ": " << (st.size() != n ? "YES" : "NO") << "\n";
  }

  return 0;
}
