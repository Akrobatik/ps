// Title : 부분 문자열
// Link  : https://www.acmicpc.net/problem/6550 
// Time  : 0 ms
// Memory: 2392 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  while (cin >> s >> t) {
    int idx = 0;
    for (int i = 0; i < t.size(); i++) {
      if (s[idx] == t[i]) {
        if (++idx == s.size()) break;
      }
    }

    cout << (idx == s.size() ? "Yes\n" : "No\n");
  }

  return 0;
}
