// Title : 잠수함식별
// Link  : https://www.acmicpc.net/problem/2671 
// Time  : 0 ms
// Memory: 2172 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  regex re("^(100+1+|01)+$");
  cout << (regex_match(s, re) ? "SUBMARINE" : "NOISE");

  return 0;
}