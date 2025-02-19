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
    bool ok = true;
    char str[12];
    for (int i = 0; i < n; i++) {
      cin >> str;
      if (!ok) continue;
      int64_t key = 0;
      for (auto ptr = str; *ptr; ++ptr) key = (key << 4) | (table[*ptr - 'A'] + 1);
      ok = st.insert(key).second;
    }

    cout << "Case #" << ti << ": " << (ok ? "NO" : "YES") << "\n";
  }

  return 0;
}
