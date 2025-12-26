// Title : 덕후
// Link  : https://www.acmicpc.net/problem/34921 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, t;
  cin >> a >> t;

  int x = 10 + 2 * (25 - a + t);
  cout << max<int>(x, 0);

  return 0;
}