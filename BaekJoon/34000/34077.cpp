// Title : 폴카의 수학 공부
// Link  : https://www.acmicpc.net/problem/34077 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    auto pos = s.find('-');
    if (pos == string::npos) {
      cout << "YES\n";
      continue;
    }
    ++pos;

    while (pos < s.size() && '0' <= s[pos] && s[pos] <= '9') ++pos;

    bool ok = true;
    for (int i = pos; i < s.size(); i++) {
      if ('1' <= s[i] && s[i] <= '9') {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
