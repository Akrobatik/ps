// Title : SciComLove (2025)
// Link  : https://www.acmicpc.net/problem/33810 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kStr = "SciComLove";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  char s[12];
  cin >> s;
  int cnt = 0;
  for (int i = 0; s[i]; i++) {
    cnt += (s[i] != kStr[i]);
  }
  cout << cnt;

  return 0;
}
