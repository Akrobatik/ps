// Title : WARBOY
// Link  : https://www.acmicpc.net/problem/26082 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  cout << (b / a) * c * 3;

  return 0;
}