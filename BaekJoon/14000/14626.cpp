// Title : ISBN
// Link  : https://www.acmicpc.net/problem/14626 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(const string& s) {
  int x = 0;
  for (int i = 0; i < 12; i++) {
    x += (s[i] - '0') * ((i & 1) ? 3 : 1);
  }
  return s[12] - '0' == (10 - x % 10) % 10;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int idx = 0;
  while (s[idx] != '*') ++idx;

  for (int i = 0; i < 10; i++) {
    s[idx] = i + '0';
    if (Check(s)) {
      cout << i;
      break;
    }
  }

  return 0;
}
