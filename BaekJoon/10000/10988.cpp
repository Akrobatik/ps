// Title : 팰린드롬인지 확인하기
// Link  : https://www.acmicpc.net/problem/10988 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size(), half = n >> 1;
  bool ok = true;
  for (int i = 0; ok && i < half; i++) {
    ok = (s[i] == s[n - i - 1]);
  }
  cout << ok;

  return 0;
}
