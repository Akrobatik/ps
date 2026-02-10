// Title : Lucky 7
// Link  : https://www.acmicpc.net/problem/30224 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int x = 0;
  x |= (stoi(s) % 7 == 0);
  x |= (s.find('7') != string::npos ? 2 : 0);
  cout << x;

  return 0;
}