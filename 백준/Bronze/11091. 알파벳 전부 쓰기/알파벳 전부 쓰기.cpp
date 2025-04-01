#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int t;
  cin >> t;
  getline(cin, s);
  while (t--) {
    getline(cin, s);
    int memo[26] = {};
    for (auto c : s) {
      if (isalpha(c)) ++memo[tolower(c) - 'a'];
    }

    bool ok = true;
    for (int i = 0; ok && i < 26; i++) {
      ok = (memo[i] != 0);
    }

    if (ok) {
      cout << "pangram\n";
    } else {
      cout << "missing ";
      for (int i = 0; i < 26; i++) {
        if (memo[i]) continue;
        cout << (char)(i + 'a');
      }
      cout << "\n";
    }
  }

  return 0;
}
