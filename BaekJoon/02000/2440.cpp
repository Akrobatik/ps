// Title : 별 찍기 - 3
// Link  : https://www.acmicpc.net/problem/2440 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  string s(n, '*');
  while (!s.empty()) cout << s << "\n", s.pop_back();

  return 0;
}
