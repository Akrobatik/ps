// Title : 창고 다각형
// Link  : https://www.acmicpc.net/problem/2304
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> m;
  int maxh = 0, maxl, maxr;
  while (n--) {
    int l, h;
    cin >> l >> h;
    m[l] = h;
    if (maxh < h) {
      maxh = h;
      maxl = maxr = l;
    } else if (maxh == h) {
      if (maxl > l) {
        maxl = l;
      } else if (maxr < l) {
        maxr = l;
      }
    }
  }

  int sum = maxh * (maxr - maxl + 1);
  int prvl = 0, prvh = 0;
  for (auto [l, h] : m) {
    if (prvl) sum += prvh * (l - prvl);
    prvl = l;
    if (prvh < h) prvh = h;
    if (prvh == maxh) break;
  }
  prvl = 0, prvh = 0;
  for (auto [l, h] : views::reverse(m)) {
    if (prvl) sum += prvh * (prvl - l);
    prvl = l;
    if (prvh < h) prvh = h;
    if (prvh == maxh) break;
  }
  cout << sum;

  return 0;
}
