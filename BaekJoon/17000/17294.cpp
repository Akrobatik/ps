// Title : 귀여운 수~ε٩(๑> ₃ <)۶з
// Link  : https://www.acmicpc.net/problem/17294 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  bool ok = true;
  for (int i = 1; ok && i < n; i++) {
    ok = (s[1] - s[0] == s[i] - s[i - 1]);
  }

  cout << (ok ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>");

  return 0;
}