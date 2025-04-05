// Title : 포린드롬
// Link  : https://www.acmicpc.net/problem/33690
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
  if (n == 1) {
    cout << stoi(s) + 1;
    return 0;
  }

  int ans = (n - 1) * 9 + 1;
  string tmp(n, s[0]);
  ans += s[0] - '1' + (s.compare(tmp) >= 0);
  cout << ans;

  return 0;
}