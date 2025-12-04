// Title : Strawberry
// Link  : https://www.acmicpc.net/problem/34799 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int64_t n;
  cin >> s >> n;

  int64_t cnt[26] = {};
  for (auto c : s) ++cnt[(c - 'r' + 26) % 26];

  int64_t all = s.size();
  int64_t ans = all * (n / 26);
  for (int i = 0; i < n % 26; i++) ans += cnt[i];

  cout << ans;

  return 0;
}