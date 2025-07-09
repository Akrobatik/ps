// Title : 어린 왕자
// Link  : https://www.acmicpc.net/problem/1004 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int sy, sx, dy, dx, n;
    cin >> sy >> sx >> dy >> dx >> n;
    int cnt = 0;
    while (n--) {
      int y, x, r;
      cin >> y >> x >> r;
      bool sb = (y - sy) * (y - sy) + (x - sx) * (x - sx) < r * r;
      bool db = (y - dy) * (y - dy) + (x - dx) * (x - dx) < r * r;
      cnt += (sb != db);
    }
    cout << cnt << "\n";
  }

  return 0;
}
