// Title : 어게인 포닉스
// Link  : https://www.acmicpc.net/problem/33950 
// Time  : 0 ms
// Memory: 2024 KB

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
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (i + 1 != n && s[i] == 'P' && s[i + 1] == 'O') {
        cout << "PHO";
        ++i;
      } else {
        cout << s[i];
      }
    }
    cout << "\n";
  }

  return 0;
}