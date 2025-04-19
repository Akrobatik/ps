// Title : 터렛
// Link  : https://www.acmicpc.net/problem/1002 
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
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if (r1 > r2) {
      swap(x1, x2);
      swap(y1, y2);
      swap(r1, r2);
    }

    int ds = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (ds == 0 && r1 == r2) {
      cout << "-1\n";
    } else if ((r1 + r2) * (r1 + r2) < ds || (r2 - r1) * (r2 - r1) > ds) {
      cout << "0\n";
    } else if ((r1 + r2) * (r1 + r2) == ds || (r2 - r1) * (r2 - r1) == ds) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }

  return 0;
}
