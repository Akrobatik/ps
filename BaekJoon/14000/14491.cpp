// Title : 9진수
// Link  : https://www.acmicpc.net/problem/14491
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  cin >> x;
  int n = 0;
  char s[32];
  while (x || !n) s[n++] = x % 9 + '0', x /= 9;
  while (n--) cout << s[n];

  return 0;
}
