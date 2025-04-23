// Title : 뒤집힌 덧셈
// Link  : https://www.acmicpc.net/problem/1357 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;
  while (s1.back() == '0') s1.pop_back();
  reverse(s1.begin(), s1.end());
  while (s2.back() == '0') s2.pop_back();
  reverse(s2.begin(), s2.end());

  string s3 = to_string(stoi(s1) + stoi(s2));
  while (s3.back() == '0') s3.pop_back();
  reverse(s3.begin(), s3.end());
  cout << s3;

  return 0;
}
