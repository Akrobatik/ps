// Title : Treasure Hunt
// Link  : https://www.acmicpc.net/problem/34645 
// Time  : 0 ms
// Memory: 13680 KB

#include <bits/stdc++.h>

using namespace std;

int Query(int y, int x) {
  cout << "? " << y << " " << x << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int y = 2, x = 2;
  for (int i = 1; i <= 3; i++) {
    int yy = y + ((i & 1) ? 2 : 0);
    int xx = x + ((i & 2) ? 2 : 0);
    if (Query(yy, xx)) {
      y = yy, x = xx;
      break;
    }
  }

  if (Query(y - 1, x)) --y;
  if (Query(y, x - 1)) --x;
  cout << "! " << y << " " << x << endl;

  return 0;
}