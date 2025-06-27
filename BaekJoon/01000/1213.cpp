// Title : 팰린드롬 만들기
// Link  : https://www.acmicpc.net/problem/1213 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int cnt[26] = {};
  for (auto c : s) ++cnt[c - 'A'];

  int odd = 0;
  for (auto e : cnt) odd += (e & 1);

  if (odd > 1) {
    cout << "I'm Sorry Hansoo";
  } else {
    s.clear();
    for (int i = 0; i < 26; i++) {
      auto& x = cnt[i];
      while (x >= 2) s.push_back(i + 'A'), x -= 2;
    }

    cout << s;
    if (odd) {
      int i = 0;
      while (cnt[i] == 0) ++i;
      cout << (char)(i + 'A');
    }
    reverse(s.begin(), s.end());
    cout << s;
  }

  return 0;
}
