// Title : 한글
// Link  : https://www.acmicpc.net/problem/11282 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int uni = 0xAC00 + n - 1;
  int utf = (0xE0 | ((uni >> 12) & 0x0F)) |
                 ((0x80 | ((uni >> 6) & 0x3F)) << 8) |
                 ((0x80 | (uni & 0x3F)) << 16);

  cout.write((const char*)&utf, 3);

  return 0;
}
