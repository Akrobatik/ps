// Title : Darius님 한타 안 함?
// Link  : https://www.acmicpc.net/problem/20499 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  getline(cin, s, '/');
  int k = stoi(s);
  getline(cin, s, '/');
  int d = stoi(s);
  getline(cin, s, '/');
  int a = stoi(s);

  cout << ((k + a < d || d == 0) ? "hasu" : "gosu");

  return 0;
}
