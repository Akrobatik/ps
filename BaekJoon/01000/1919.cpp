// Title : 애너그램 만들기
// Link  : https://www.acmicpc.net/problem/1919
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  int m1[26] = {}, m2[26] = {};
  for (auto c : s1) ++m1[c - 'a'];
  for (auto c : s2) ++m2[c - 'a'];

  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int minn = min<int>(m1[i], m2[i]);
    int maxx = m1[i] ^ m2[i] ^ minn;
    ans += maxx - minn;
  }
  cout << ans;

  return 0;
}
