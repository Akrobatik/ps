// Title : 안정적인 문자열
// Link  : https://www.acmicpc.net/problem/4889 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 0;

  string s;
  while (cin >> s && count(s.begin(), s.end(), '-') == 0) {
    int cnt = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
      cnt += (s[i] == '{' ? 1 : -1);
      if (cnt < 0) cnt += 2, ++ans;
    }
    cout << ++t << ". " << ans + (cnt / 2) << "\n";
  }

  return 0;
}
