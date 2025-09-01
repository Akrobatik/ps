// Title : 솹씨 몇 도예요?
// Link  : https://www.acmicpc.net/problem/34187 
// Time  : 4 ms
// Memory: 13816 KB

#include <bits/stdc++.h>

using namespace std;

int Query(int x) {
  cout << "? " << x << endl;

  string s;
  cin >> s;
  return s[0] == 'H' ? -1 : (s[0] == 'C' ? 1 : 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int lo = 0, hi = 2025;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int res = Query(mid);
    if (res == 0) {
      lo = hi = mid;
      break;
    }

    if (res < 0) {
      lo = (lo + mid) >> 1;
      hi = mid - 1;
    } else {
      lo = mid;
      hi = (hi + mid) >> 1;
    }
  }
  cout << "! " << lo << endl;

  return 0;
}
