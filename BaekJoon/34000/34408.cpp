// Title : 문자열 분해기
// Link  : https://www.acmicpc.net/problem/34408 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  int cnt[256] = {};
  for (auto c : s) ++cnt[c];

  bool ok = true;
  for (auto c : t) {
    ok &= (--cnt[c] >= 0);
  }

  cout << (ok ? "OK" : "NEED FIX");

  return 0;
}