// Title : 아!
// Link  : https://www.acmicpc.net/problem/4999 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1, s2;
  cin >> s1 >> s2;

  cout << (s1.size() >= s2.size() ? "go" : "no");

  return 0;
}
