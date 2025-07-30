// Title : 이 문제는 D2 입니다.
// Link  : https://www.acmicpc.net/problem/23303 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s);
  for (auto& c : s) {
    if (isalpha(c) && c < 'a') c ^= 32;
  }

  cout << (s.find("d2") != string::npos ? "D2" : "unrated");

  return 0;
}
