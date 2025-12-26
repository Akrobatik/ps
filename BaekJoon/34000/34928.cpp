// Title : PAUL 문자열 (Hard)
// Link  : https://www.acmicpc.net/problem/34928 
// Time  : 0 ms
// Memory: 2392 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int memo[5][2] = {};
  memo[0][0] = memo[0][1] = 1;

  for (int i = 0; i < n; i++) {
    int a = 0, b = i & 1, c = s[i];
    if (c == 'P') {
      a = 1;
    } else if (c == 'A') {
      a = 2;
    } else if (c == 'U') {
      a = 3;
    } else if (c == 'L') {
      a = 4;
    }

    if (a > 0 && memo[a - 1][b ^ 1]) {
      memo[a][b] = 1;
    }
  }

  cout << (memo[4][1] && (~n & 1) ? "YES" : "NO");

  return 0;
}