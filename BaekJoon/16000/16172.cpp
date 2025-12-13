// Title : 나는 친구가 적다 (Large)
// Link  : https://www.acmicpc.net/problem/16172 
// Time  : 8 ms
// Memory: 3088 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2, s3;
  cin >> s1 >> s2;

  for (auto c : s1) {
    if (isalpha(c)) s3.push_back(c);
  }

  cout << (strstr(s3.data(), s2.data()) != nullptr);

  return 0;
}