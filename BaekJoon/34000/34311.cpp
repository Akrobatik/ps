// Title : QWERTY
// Link  : https://www.acmicpc.net/problem/34311 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr const char* kTable = "qwertyuiopasdfghjklzxcvbnm";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);
  getline(cin, s);
  for (auto c : s) {
    if ('a' <= c && c <= 'z') {
      cout << kTable[c - 'a'];
    } else {
      cout << c;
    }
  }

  return 0;
}