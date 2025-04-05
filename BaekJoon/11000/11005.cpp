// Title : 진법 변환 2
// Link  : https://www.acmicpc.net/problem/11005
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

char ToChar(int ch) {
  if (ch < 10) return ch + '0';
  return ch + 'A' - 10;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;

  int n = 0;
  char s[32];
  while (a || !n) s[n++] = ToChar(a % b), a /= b;
  while (n--) cout << s[n];

  return 0;
}
