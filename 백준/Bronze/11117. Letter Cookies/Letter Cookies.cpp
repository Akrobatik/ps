#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int m1[26] = {};
    for (auto c : s) ++m1[c - 'A'];

    int n;
    cin >> n;
    while (n--) {
      cin >> s;
      int m2[26] = {};
      for (auto c : s) ++m2[c - 'A'];
      bool ok = true;
      for (int i = 0; ok && i < 26; i++) {
        ok = (m1[i] >= m2[i]);
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
