// Title : 네 번째 점
// Link  : https://www.acmicpc.net/problem/3009 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int y1, x1, y2, x2, y3, x3;
  cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3;
  cout << (y1 ^ y2 ^ y3) << " " << (x1 ^ x2 ^ x3);

  return 0;
}
