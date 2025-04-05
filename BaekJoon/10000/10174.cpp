// Title : 팰린드롬
// Link  : https://www.acmicpc.net/problem/10174
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n;
  getline(cin, s);
  while (n--) {
    getline(cin, s);
    for (auto& c : s) {
      if (isalpha(c)) c = tolower(c);
    }
    int sn = s.size(), half = sn >> 1;
    bool ok = true;
    for (int i = 0; ok && i < half; i++) {
      ok = (s[i] == s[sn - i - 1]);
    }
    cout << (ok ? "Yes\n" : "No\n");
  }

  return 0;
}
