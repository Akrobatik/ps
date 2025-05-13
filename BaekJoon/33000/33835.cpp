// Title : 도로 공사
// Link  : https://www.acmicpc.net/problem/33835 
// Time  : 24 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int sy, sx, dy, dx;
  cin >> n >> sy >> sx;
  while (--n) cin >> dy >> dx;
  auto d = hypot((double)abs(sy - dy), (double)abs(sx - dx));
  cout << setprecision(4) << fixed << d;

  return 0;
}
