// Title : C）
// Link  : https://www.acmicpc.net/problem/33693
// Time  : 72 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;

  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    int n = s.size(), cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      int rem = n - i;
      if (s[i] == 'C') {
        if (cnt != rem) {
          s[i] = '(';
          ++cnt;
        } else {
          s[i] = ')';
          --cnt;
          ans += 2;
        }
      } else {
        if (cnt == 0) {
          s[i] = '(';
          ++cnt;
          ++ans;
        } else {
          s[i] = ')';
          --cnt;
          ++ans;
        }
      }
    }
    cout << ans << "\n" << s << "\n";
  }

  return 0;
}