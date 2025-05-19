// Title : 일기 암호화하기
// Link  : https://www.acmicpc.net/problem/33869 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  bool check[26] = {};

  string s1, s2;
  cin >> s1 >> s2;
  string key;
  for (auto c : s1) {
    if (!check[c - 'A']) key.push_back(c);
    check[c - 'A'] = true;
  }

  for (int i = 0; i < 26; i++) {
    if (check[i]) continue;
    key.push_back(i + 'A');
  }

  for (auto c : s2) cout << key[c - 'A'];

  return 0;
}
