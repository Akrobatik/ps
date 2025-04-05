// Title : 개미
// Link  : https://www.acmicpc.net/problem/4307
// Time  : 28 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int l, n;
    cin >> l >> n;
    int minn = 0, maxx = 0;
    while (n--) {
      int x;
      cin >> x;
      int xmax = max<int>(x, l - x);
      int xmin = min<int>(x, l - x);
      if (maxx < xmax) maxx = xmax;
      if (minn < xmin) minn = xmin;
    }
    cout << minn << " " << maxx << "\n";
  }

  return 0;
}
