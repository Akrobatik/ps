// Title : CCW
// Link  : https://www.acmicpc.net/problem/11758 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int CCW(int ay, int ax, int by, int bx, int cy, int cx) {
  int cp = (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
  return (cp > 0) - (cp < 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ay, ax, by, bx, cy, cx;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  cout << CCW(ay, ax, by, bx, cy, cx);

  return 0;
}
