// Title : ko_orange
// Link  : https://www.acmicpc.net/problem/22901 
// Time  : 184 ms
// Memory: 13948 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int x) {
  cout << "? " << x << endl;
  cin >> x;
  return x != 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    bool f = true, q = false, b;
    int lo = 2100, hi = 2400, ml, mh;
    while (lo + 1 < hi) {
      int mid = (lo + hi) >> 1;
      if (b = Check(mid)) {
        ml = lo, mh = hi;
        lo = mid;
        q = f;
      } else {
        if (q && !Check((ml + mh) >> 1)) {
          lo = ml, hi = (ml + mh) >> 1;
          f = q = false;
        } else {
          hi = mid;
          q = false;
        }
      }
    }

    if (b && f && !Check((ml + mh) >> 1)) {
      lo = ml;
    }
    cout << "! " << lo - (!b && q && !Check((ml + mh) >> 1)) << endl;
  }

  return 0;
}
