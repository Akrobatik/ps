// Title : UCPC는 무엇의 약자일까?
// Link  : https://www.acmicpc.net/problem/15904 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kStr = "UCPC";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);

  int idx = 0;
  for (auto c : s) {
    if (c == kStr[idx]) ++idx;
    if (idx == 4) break;
  }
  cout << (idx == 4 ? "I love UCPC" : "I hate UCPC");

  return 0;
}
