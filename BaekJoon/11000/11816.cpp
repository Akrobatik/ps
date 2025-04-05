// Title : 8진수， 10진수， 16진수
// Link  : https://www.acmicpc.net/problem/11816
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  if (s.starts_with("0x")) {
    cout << stoi(s, 0, 16);
  } else if (s.starts_with("0")) {
    cout << stoi(s, 0, 8);
  } else {
    cout << stoi(s, 0, 10);
  }

  return 0;
}
