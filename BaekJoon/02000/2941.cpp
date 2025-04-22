// Title : 크로아티아 알파벳
// Link  : https://www.acmicpc.net/problem/2941 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  auto Next = [&](int i) {
    if (i + 3 <= s.size()) {
      if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') return 3;
    }
    if (i + 2 <= s.size()) {
      if (s[i] == 'c' && s[i + 1] == '=') return 2;
      if (s[i] == 'c' && s[i + 1] == '-') return 2;
      if (s[i] == 'd' && s[i + 1] == '-') return 2;
      if (s[i] == 'l' && s[i + 1] == 'j') return 2;
      if (s[i] == 'n' && s[i + 1] == 'j') return 2;
      if (s[i] == 's' && s[i + 1] == '=') return 2;
      if (s[i] == 'z' && s[i + 1] == '=') return 2;
    }
    return 1;
  };

  int idx = 0, cnt = 0;
  while (idx < s.size()) idx += Next(idx), ++cnt;
  cout << cnt;

  return 0;
}
